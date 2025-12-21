#include <stdio.h>
#include <stdlib.h>
#include "responsive.h"

/**
 * Builds a new DisplayInfo.
 */
DisplayInfo* newDisplayInfo(
    unsigned int width,
    unsigned int height,
    float frames
)
{
    DisplayInfo* new = malloc(sizeof(DisplayInfo));
    new->Width = width;
    new->Height = height;
    new->Frames = frames;
    return new;
}

/**
 * Converts viewport width percentage to pixel count.
 * Always returns a positive value.
 */
float vw_ToPixels(float vw, const DisplayInfo *dinfo)
{
    if (vw < 0)
        vw = -vw;

    float percent = (float)dinfo->Width / 100.0;
    return percent * vw;
}

/**
 * Converts viewport height percentage to pixel count.
 * Always returns a positive value.
 */
float vh_ToPixels(float vh, const DisplayInfo* dinfo)
{
    if (vh < 0)
        vh = -vh;

    float percent = (float)dinfo->Height / 100.0;
    return percent * vh;
}