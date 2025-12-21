/**
 * Holds information about the display.
 */
typedef struct DisplayInfo
{
    /**
     * Width of the game window in pixels.
     */
    unsigned int Width;
    /**
     * Height of the game window in pixels.
     */
    unsigned int Height;

    /**
     * Amount of frames to be displayed in a second.
     */
    float Frames;
} DisplayInfo;

/**
 * Builds a new DisplayInfo.
 */
DisplayInfo* newDisplayInfo(
    unsigned int width,
    unsigned int height,
    float frames
);

/**
 * Converts viewport width percentage to pixel count.
 * Always returns a positive value.
 */
float vw_ToPixels(float vw, const DisplayInfo* dinfo);

/**
 * Converts viewport height percentage to pixel count.
 * Always returns a positive value.
 */
float vh_ToPixels(float vh, const DisplayInfo* dinfo);