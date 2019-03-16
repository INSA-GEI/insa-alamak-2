/*
 * detection.h
 *
 *  Created on: Mar 14, 2019
 *      Author: MasterChief
 */

#ifndef DETECTION_H_
#define DETECTION_H_

#define STRAIGHT					1
#define CURVE						2
#define CROSS						0
#define UNDEFINE_CASE				5
#define	ENDLINE						6
#define MAX_DETECTION				20
#define MIN_DETECTION				0
#define	DETECTION_TRIGGER			10

void update_corrector_type(int number_detection);

/*ADD 3 variables in MAIN:
int *nbr_detection_straight;
int *nbr_detection_curve;
int *type_detection;

in the init add this code:
*nbr_detection_straight=100;
*nbr_detection_curve=50;
*type=STRAIGHT;

use "type" as a variable to choose the corrector depending on the case;

use update_corrector_type in image_processing algorithm

*/

#endif /* DETECTION_H_ */
