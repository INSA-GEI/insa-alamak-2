/*
 * detection.c
 *
 *  Created on: Mar 14, 2019
 *      Author: MasterChief
 */
#include "detection.h"
#include "camera.h"	/* include camera functions definition */
#include "math.h"	/* used for different calculations, including the difference of Gaussian with roots, exponential and PI */
#include "stdio.h"
#include "stdlib.h"
//MODE for update_detection_type
int nbr_detection_straight=MAX_DETECTION;
int nbr_detection_curve=MIN_DETECTION;
int nbr_detection_endline=MIN_DETECTION;
int nbr_detection_undefine=MIN_DETECTION;
int nbr_detection_cross=MIN_DETECTION;
int type_detection=STRAIGHT;

void update_corrector_type(int number_detection)
{
	
	if (number_detection == CROSS)
	{
		if (nbr_detection_cross<MAX_DETECTION)
		{
			nbr_detection_cross+=1;
		}
		if (nbr_detection_curve>MIN_DETECTION)
		{
			nbr_detection_curve-=1;
		}
		if (nbr_detection_straight>MIN_DETECTION)
		{
			nbr_detection_straight-=1;
		}
		if (nbr_detection_endline>MIN_DETECTION)
		{
			nbr_detection_endline-=1;
		}
	}
	if (number_detection==STRAIGHT)
	{
		if (nbr_detection_straight<MAX_DETECTION)
		{
			nbr_detection_straight+=1;
		}
		if (nbr_detection_curve>MIN_DETECTION)
		{
			nbr_detection_curve-=1;
		}
		if (nbr_detection_endline>MIN_DETECTION)
		{
			nbr_detection_endline-=1;
		}
		if (nbr_detection_cross>MIN_DETECTION)
		{
			nbr_detection_cross-=1;
		}
	}
	
	else if (number_detection==CURVE)
	{
		if (nbr_detection_curve<MAX_DETECTION)
		{
			nbr_detection_curve+=1;
		}
		if (nbr_detection_straight>MIN_DETECTION)
		{
			nbr_detection_straight-=1;
		}
		if (nbr_detection_endline>MIN_DETECTION)
		{
			nbr_detection_endline-=1;
		}
		if (nbr_detection_cross>MIN_DETECTION)
		{
			nbr_detection_cross-=1;
		}
	}
	
	else if (number_detection >= ENDLINE && number_detection <= UNDEFINE_CASE)
	{
		if (nbr_detection_endline<MAX_DETECTION)
		{
			nbr_detection_endline+=1;
		}
		if (nbr_detection_curve>MIN_DETECTION)
		{
			nbr_detection_curve-=1;
		}
		if (nbr_detection_straight>MIN_DETECTION)
		{
			nbr_detection_straight-=1;
		}
		if (nbr_detection_cross>MIN_DETECTION)
		{
			nbr_detection_cross-=1;
		}
	}
	
	
	
	
	if (nbr_detection_straight>DETECTION_TRIGGER)
	{
		type_detection=STRAIGHT;
		GPIOB_PDOR &= ~GPIO_PDOR_PDO(1<<19);   // green LED off
		GPIOD_PDOR &= ~GPIO_PDOR_PDO(1<<1);    // blue LED off	
		GPIOB_PDOR &= ~GPIO_PDOR_PDO(1<<18);	// red led on
	}
	if (nbr_detection_curve>DETECTION_TRIGGER)
	{
		type_detection=CURVE;
		GPIOB_PDOR |= GPIO_PDOR_PDO(1<<19);   // green LED off
		GPIOD_PDOR &= ~GPIO_PDOR_PDO(1<<1);    // blue LED on	
		GPIOB_PDOR |= GPIO_PDOR_PDO(1<<18);	// red led off
	}
	if (nbr_detection_endline>DETECTION_TRIGGER)
	{
		type_detection=ENDLINE;
		GPIOB_PDOR |= GPIO_PDOR_PDO(1<<19);   // green LED off
		GPIOD_PDOR |= GPIO_PDOR_PDO(1<<1);    // blue LED on	
		GPIOB_PDOR &= ~GPIO_PDOR_PDO(1<<18);	// red led off
	}
	if (nbr_detection_cross > DETECTION_TRIGGER && type_detection == STRAIGHT)
	{
		type_detection=CROSS;
		GPIOB_PDOR &= ~GPIO_PDOR_PDO(1<<19);   // green LED off
		GPIOD_PDOR |= GPIO_PDOR_PDO(1<<1);    // blue LED on	
		GPIOB_PDOR |= GPIO_PDOR_PDO(1<<18);	// red led off
		
	}
}
