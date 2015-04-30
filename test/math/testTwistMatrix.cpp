/****************************************************************************
 *
 * $Id$
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2014 by INRIA. All rights reserved.
 * 
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * ("GPL") version 2 as published by the Free Software Foundation.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact INRIA about acquiring a ViSP Professional 
 * Edition License.
 *
 * See http://www.irisa.fr/lagadic/visp/visp.html for more information.
 * 
 * This software was developed at:
 * INRIA Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 * http://www.irisa.fr/lagadic
 *
 * If you have questions regarding the use of this file, please contact
 * INRIA at visp@inria.fr
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * Description:
 * Tests some vpMatrix functionalities.
 *
 * Authors:
 * Fabien Spindler
 *
 *****************************************************************************/

/*!
  \example testTwistMatrix.cpp

  \brief Test some vpMatrix functionalities.
*/



#include <visp/vpConfig.h>
#include <visp/vpDebug.h>

#include <stdlib.h>
#include <stdio.h>

#include <visp/vpMath.h>
#include <visp/vpMatrix.h>
#include <visp/vpColVector.h>
#include <visp/vpRxyzVector.h>
#include <visp/vpTranslationVector.h>
#include <visp/vpRotationMatrix.h>
#include <visp/vpVelocityTwistMatrix.h>

int
main()
{
  try {
    vpTRACE("--------------------------");
    vpTRACE("--- TEST vpVelocityTwistMatrix ---");
    vpTRACE("--------------------------");

    // Set the translation
    vpTranslationVector cte;
    cte[0] = 1.;
    cte[1] = 0.5;
    cte[2] = -1.;

    // Set the rotation
    vpRxyzVector cre;
    cre[0] =  M_PI/2.;
    cre[1] = -M_PI/2.;
    cre[2] = -M_PI/4.;

    // Build rotation matrix
    vpRotationMatrix cRe(cre);

    // Build the twist matrix
    vpVelocityTwistMatrix cVe(cte, cRe);

    vpTRACE("cVe twist matrix:");
    cVe.print (std::cout, 6);


    // Set a speed skew
    vpColVector ev(6);

    ev[0] = 1.;
    ev[1] = 0.1;
    ev[2] = -0.5;
    ev[3] = M_PI/180.;
    ev[4] = M_PI/18.;
    ev[5] = M_PI/10.;

    vpTRACE("ev colvector:");
    ev.print (std::cout, 6);

    // Set a speed skew
    vpColVector cv;

    cv = cVe * ev;

    vpTRACE("cv = cVe * ev:");
    cv.print (std::cout, 6);
    return 0;
  }
  catch(vpException e) {
    std::cout << "Catch an exception: " << e << std::endl;
    return 1;
  }
}
