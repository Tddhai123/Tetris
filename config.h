#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <SDL2/SDL.h>

namespace config {
    // Window title
    const char window_title[] = "Tetris";

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 360;
    extern int score;
    extern double resolution_scaling;                               // Default scaling of the logical resolution; 1 means 360p, 2 means 720p etc.
    extern double available_resolution_scalings[];                  // Resolution scalings available in the options
    const int possible_resolution_scalings = 6;                     // Number of available resolution scalings

    // Board class
    const int width_to_playfield = 242;                             // in pixels
    const int height_to_playfield = 34;                             // in pixels
    const int block_size = 16;                                      // in pixels
    const int playfield_width = 10;                                 // in blocks
    const int playfield_height = 22;                                // The playfield+2 rows directly above it for spawning the Tetrominos
    const int true_playfield_height = 20;                           // in blocks
    const int frame_width = 6;                                      // Frame that surrounds the playfield; in pixels
    const int frame_sprite_size = 8;                                // Size of each sprite clip for the playfield frame
    const int matrix_blocks = 5;                                    // matrix that holds tetromino info; in blocks

    // GameState class
    const int next_box_x = 405;                                     // Horizontal distance from top left corner; in pixels
    const int next_box_y = 10;                                      // Horizontal distance from top left corner; in pixels

    const int hold_box_x = 150;                                     // Horizontal distance from top left corner; in pixels
    const int hold_box_y = 10;                                      // Vertical distance from top left corner; in pixels

    // Constants relating to Tetris
    const int wait_time = 1000;                                     // Time in milliseconds
    extern bool ghost_piece_enabled;                                // Enables or disables the ghost piece to reduce misdrops

    // Visuals
    const SDL_Color default_text_color = {0x00, 0x00, 0x00, 0xFF};  // Default color for all text
    const Uint8 background_r_light = 0xF9;                          // Background color for light mode
    const Uint8 background_g_light = 0xE6;
    const Uint8 background_b_light = 0xCF;
    const Uint8 transparency_alpha = 100;                                  // Default alpha for transparency (with 255 being no transparency)
}

#endif // CONFIG_H_INCLUDED
