#include <GL/glut.h>
#include<cmath>

/// Function to draw the circle
void drawCircle(float centerX, float centerY, float radius) {
    glBegin(GL_POLYGON); // Draw a polygon to approximate the circle
    for (int i = 0; i < 290; i++) {
        float theta = i * 3.1415926 / 180.0; // Convert degrees to radians
        float x = radius * cos(theta) + centerX; // X coordinate of the circle
        float y = radius * sin(theta) + centerY; // Y coordinate of the circle
        glVertex2f(x, y); // Add a vertex to the polygon
    }
    glEnd();
}
/// Global variable for cloud movement
float cloudOffset = 0.0f; // Horizontal offset for clouds

/// Function to draw clouds
void drawCloud(float x, float y, float size) {
    glColor3f(1.0, 1.0, 1.0); // Cloud color (white)
    // Draw overlapping circles for a fluffy cloud effect with horizontal offset
    drawCircle(x + cloudOffset, y, size);
    drawCircle(x + cloudOffset + size * 0.5, y, size * 0.7);
    drawCircle(x + cloudOffset - size * 0.5, y, size * 0.6);
    drawCircle(x + cloudOffset, y + size * 0.3, size * 0.5);
}

/// Function to draw the sun
void drawSun() {
    // Move the sun to a visible position, for example, (0.7, 0.7) with a radius of 0.2
    glColor3f(1.0, 0.7, 0.2); // Sun color (yellow)
    drawCircle(1, 1, 0.5); // Position of the sun within the [-1, 1] range
}
    /// Function to draw a more realistic, smaller village house
    void drawVillageHouse() {
        // Draw the house's base (a smaller rectangle)
        glColor3f(0.8, 0.6, 0.4);  // Brown color for the house base
        glBegin(GL_QUADS);  // Start drawing a quadrilateral (rectangle)
        glVertex2f(-0.2, -0.4);  // Bottom left corner
        glVertex2f(0.2, -0.4);   // Bottom right corner
        glVertex2f(0.2, 0.0);    // Top right corner
        glVertex2f(-0.2, 0.0);   // Top left corner
        glEnd();

        // Draw the roof (a more detailed, slanted triangle)
        glColor3f(0.7, 0.3, 0.1);  // Darker brown for the roof
        glBegin(GL_TRIANGLES);  // Start drawing a triangle
        glVertex2f(-0.25, 0.0);   // Left corner of the roof
        glVertex2f(0.25, 0.0);    // Right corner of the roof
        glVertex2f(0.0, 0.3);     // Peak of the roof
        glEnd();

        // Add a roof overhang to make it more realistic
        glColor3f(0.7, 0.3, 0.1);  // Same brown color for consistency
        glBegin(GL_QUADS);
        glVertex2f(-0.25, 0.0);   // Bottom left corner of the overhang
        glVertex2f(0.25, 0.0);    // Bottom right corner of the overhang
        glVertex2f(0.3, -0.05);   // Right end of the overhang
        glVertex2f(-0.3, -0.05);  // Left end of the overhang
        glEnd();

        /// Draw the door (a wooden door with a more realistic shape)
        glColor3f(0.4, 0.2, 0.0);  // Dark brown color for the door
        glBegin(GL_QUADS);
        glVertex2f(-0.07, -0.4);  // Bottom left corner of the door
        glVertex2f(0.07, -0.4);   // Bottom right corner of the door
        glVertex2f(0.07, -0.1);   // Top right corner of the door
        glVertex2f(-0.07, -0.1);  // Top left corner of the door
        glEnd();

    /// Draw the left window (a square window with panes)
    glColor3f(0.3, 0.3, 0.3);  // Light sky blue color for the window (glass effect)
    glBegin(GL_QUADS);
    glVertex2f(-0.22, -0.25);   // Bottom left corner of the window
    glVertex2f(-0.12, -0.25);   // Bottom right corner of the window
    glVertex2f(-0.12, -0.15);   // Top right corner of the window
    glVertex2f(-0.22, -0.15);   // Top left corner of the window
    glEnd();

    /// Draw window panes (cross lines) for the left window
    glColor3f(0.9, 0.0, 0.3);  // Dark gray color for the window panes
    glBegin(GL_LINES);
    /// Vertical line (center pane divider)
    glVertex2f(-0.17, -0.25);
    glVertex2f(-0.17, -0.15);
    /// Horizontal line (center pane divider)
    glVertex2f(-0.22, -0.20);
    glVertex2f(-0.12, -0.20);
    glEnd();

    /// Draw the right window (same design as the left window)
    glColor3f(0.3, 0.3, 0.3);  // Light sky blue color for the window
    glBegin(GL_QUADS);
    glVertex2f(0.12, -0.25);    // Bottom left corner of the window
    glVertex2f(0.22, -0.25);    // Bottom right corner of the window
    glVertex2f(0.22, -0.15);    // Top right corner of the window
    glVertex2f(0.12, -0.15);    // Top left corner of the window
    glEnd();

    /// Draw window panes (cross lines) for the right window
    glColor3f(0.9, 0.0, 0.3);  // Dark gray color for the window panes
    glBegin(GL_LINES);
    /// Vertical line (center pane divider)
    glVertex2f(0.17, -0.25);
    glVertex2f(0.17, -0.15);
    /// Horizontal line (center pane divider)
    glVertex2f(0.12, -0.20);
    glVertex2f(0.22, -0.20);
    glEnd();



    /// Add a chimney with more detail (slightly extended and angled)
    glColor3f(0.6, 0.3, 0.0);  // Darker brown color for the chimney
    glBegin(GL_QUADS);
    glVertex2f(0.05, 0.24);    // Bottom left corner of the chimney
    glVertex2f(0.1, 0.17);     // Bottom right corner of the chimney
    glVertex2f(0.1, 0.40);     // Top right corner of the chimney
    glVertex2f(0.049, 0.45);    // Top left corner of the chimney
    glEnd();

    /// Draw a pipe coming out of the chimney for more realism
    glColor3f(0.5, 0.5, 0.5);  // Gray color for the pipe
    glBegin(GL_LINES);
    glVertex2f(0.2, 0.25);  // Bottom of the pipe
    glVertex2f(0.2, 0.20);  // Top of the pipe
    glEnd();
}


    /// Function to draw a simple house next to the old house
    void drawNewHouse() {
    /// Draw the house's base (a simple rectangle)
    glColor3f(0.6, 0.4, 0.2);  // Light brown color for the base
    glBegin(GL_QUADS);
    glVertex2f(0.35, -0.5);  // Bottom left corner
    glVertex2f(0.75, -0.5);  // Bottom right corner
    glVertex2f(0.75, -0.2);  // Top right corner
    glVertex2f(0.35, -0.2);  // Top left corner
    glEnd();

    /// Draw the roof (a simple triangle)
    glColor3f(0.5, 0.2, 0.0);  // Darker brown for the roof
    glBegin(GL_TRIANGLES);
    glVertex2f(0.3, -0.2);   // Left corner of the roof
    glVertex2f(0.8, -0.2);   // Right corner of the roof
    glVertex2f(0.55, 0.1);   // Peak of the roof
    glEnd();

    /// Draw the door (a small rectangle in the center)
    glColor3f(0.4, 0.2, 0.0);  // Dark brown for the door
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.5);  // Bottom left corner of the door
    glVertex2f(0.55, -0.5);  // Bottom right corner of the door
    glVertex2f(0.55, -0.2);  // Top right corner of the door
    glVertex2f(0.45, -0.2);  // Top left corner of the door
    glEnd();

    /// Draw a window (square window)
    glColor3f(0.3, 0.6, 1.0);  // Light blue color for the window
    glBegin(GL_QUADS);
    glVertex2f(0.6, -0.35);  // Bottom left corner of the window
    glVertex2f(0.7, -0.35);  // Bottom right corner of the window
    glVertex2f(0.7, -0.25);  // Top right corner of the window
    glVertex2f(0.6, -0.25);  // Top left corner of the window
    glEnd();

    /// Draw window panes (cross lines) for the window
    glColor3f(0.5, 0.5, 0.5);  // Gray color for the window panes
    glBegin(GL_LINES);
    /// Vertical line (center divider)
    glVertex2f(0.65, -0.35);
    glVertex2f(0.65, -0.25);
    /// Horizontal line (center divider)
    glVertex2f(0.6, -0.3);
    glVertex2f(0.7, -0.3);
    glEnd();
}


    /// Function to draw realistic mountains
    void drawMountains() {
    /// Front layer mountains (closer to the viewer)
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.5, 0.2); // Dark green for shadowed areas
    glVertex2f(-1.5, -0.5);   // Left base
    glColor3f(0.3, 0.7, 0.3); // Mid-green for mid-slope
    glVertex2f(-1.0, 0.2);    // Mid-slope
    glColor3f(0.4, 0.8, 0.4); // Lighter green for the peak
    glVertex2f(-0.5, 0.6);    // First peak
    glVertex2f(0.0, 0.3);     // Connecting slope
    glVertex2f(0.5, 0.7);     // Second peak
    glColor3f(0.3, 0.6, 0.3); // Back to mid-green for mid-slope
    glVertex2f(1.0, 0.2);     // Mid-slope
    glColor3f(0.2, 0.5, 0.2); // Dark green for base
    glVertex2f(1.5, -0.5);    // Right base
    glEnd();

    /// Add snowcaps to peaks
    glColor3f(0.3, 0.7, 0.3); // Mid-green for mid-slope
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, 0.5);   // Snow on first peak
    glVertex2f(-0.5, 0.6);
    glVertex2f(-0.4, 0.55);

    glVertex2f(0.4, 0.65);    // Snow on second peak
    glVertex2f(0.5, 0.7);
    glVertex2f(0.5, 0.65);
    glEnd();

    /// Add snowcaps to peaks2
    glColor3f(0.3, 0.7, 0.3); // Mid-green for mid-slope
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, 0.5 * 0.6);   // Snow on first peak
    glVertex2f(-0.5, 0.6 * 0.6);
    glVertex2f(-0.4, 0.55 * 0.6);

    /// Distant mountains (lighter color for depth)
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.7, 0.5); // Light green for distant mountains
    glVertex2f(-2.0, -0.6);   // Left base
    glVertex2f(-1.5, 0.0);    // Left slope
    glVertex2f(-0.8, 0.3);    // First peak
    glVertex2f(0.0, 0.1);     // Connecting slope
    glVertex2f(0.8, 0.4);     // Second peak
    glVertex2f(1.5, 0.1);     // Right slope
    glVertex2f(2.0, -0.6);    // Right base
    glEnd();

    /// Fog effect at the base of the mountains
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.8, 0.8, 0.8, 0.5); // Light grey with transparency
    glBegin(GL_QUADS);
    glVertex2f(-2.0, -0.6);
    glVertex2f(2.0, -0.6);
    glVertex2f(2.0, -1.0);
    glVertex2f(-2.0, -1.0);
    glEnd();
    glDisable(GL_BLEND);
}

    void drawVillageSoilRoad() {
    /// Draw the mountains (reuse the existing mountain drawing function)
    drawMountains();

    /// Road parameters
    float startX = -1.5f;
    float endX = 1.5f;
    float roadWidth = 0.1f; // Narrower road for a village path

    /// Road Base Layer: Draw the main road
    glBegin(GL_QUAD_STRIP);
    for (float x = startX; x <= endX; x += 0.1f) {
        float curve = 0.05f * sinf(2.0f * x);  // Curved road shape
        glColor3f(0.6, 0.4, 0.2); // Brown base color
        glVertex2f(x, curve - roadWidth);
        glVertex2f(x, curve + roadWidth);
    }
    glEnd();

    /// Add Random Texture: Simulate dirt using small patches
    glPointSize(2.0); // Larger points for texture
    glBegin(GL_POINTS);
    for (float x = startX; x <= endX; x += 0.02f) {
        for (float offset = -roadWidth; offset <= roadWidth; offset += 0.02f) {
            float curve = 0.05f * sinf(2.0f * x);  // Follow the curve
            float randomVariation = 0.005f * (rand() % 10 - 5); // Random dirt texture
            glColor3f(0.55 + randomVariation, 0.35 + randomVariation, 0.2 + randomVariation);
            glVertex2f(x, curve + offset + randomVariation);
        }
    }
    glEnd();

    /// Add Grass Edges: Blend road into the environment
    glPointSize(4.0); // Grass clumps
    glBegin(GL_POINTS);
    for (float x = startX; x <= endX; x += 0.05f) {
        float curve = 0.05f * sinf(2.0f * x); // Road curve
        glColor3f(0.3, 0.6, 0.3); // Grass color
        glVertex2f(x, curve - roadWidth - 0.05f); // Bottom grass
        glVertex2f(x, curve + roadWidth + 0.05f); // Top grass
    }
    glEnd();

    /// Add Tire Marks: Slightly darker parallel lines on the road
    glBegin(GL_LINES);
    glColor3f(0.4, 0.3, 0.2); // Dark brown for tire marks
    for (float x = startX; x <= endX; x += 0.1f) {
        float curve = 0.05f * sinf(2.0f * x); // Follow the road curve
        glVertex2f(x, curve - 0.03f); // Left tire mark
        glVertex2f(x + 0.1f, curve - 0.03f);

        glVertex2f(x, curve + 0.03f); // Right tire mark
        glVertex2f(x + 0.1f, curve + 0.03f);
    }
    glEnd();

    /// Add Stones and Patches: Scattered details for realism
    glPointSize(3.0); // Small stones
    glBegin(GL_POINTS);
    for (float x = startX; x <= endX; x += 0.1f) {
        float curve = 0.05f * sinf(2.0f * x); // Follow the curve
        glColor3f(0.5, 0.4, 0.3); // Stone color
        glVertex2f(x, curve + ((rand() % 10 - 5) * 0.01f)); // Random position
    }
    glEnd();
}




    void drawGrass() {
    /// Base green color for the grass (first layer)
    glColor3f(0.1f, 0.8f, 0.1f); // Light green color for the first layer
    for (float i = -1.0f; i < 1.0f; i += 0.03f) {  // Increased spacing for more density
        float angle = (rand() % 50) - 10.0f;  // Random angle for a natural look
        float height = ((rand() % 20) / 100.0f + 0.10f) * 0.3f;  // Reduced height by 50%

        glBegin(GL_LINES);
        glVertex2f(i, -0.5f);  // Left side of the grass
        glVertex2f(i + sin(angle * M_PI / 180.0f) * height, -0.5f + cos(angle * M_PI / 180.0f) * height);
        glEnd();
    }

    /// Darker green for the second layer (adds depth)
    glColor3f(0.05f, 0.6f, 0.05f); // Darker green color for the second layer
    for (float i = -1.0f; i < 1.0f; i += 0.03f) {
        float angle = (rand() % 20) - 10.0f;
        float height = ((rand() % 20) / 100.0f + 0.10f) * 0.3f;

        glBegin(GL_LINES);
        glVertex2f(i, -0.5f);
        glVertex2f(i + sin(angle * M_PI / 180.0f) * height, -0.5f + cos(angle * M_PI / 180.0f) * height);
        glEnd();
    }

    /// Darker green for the third layer (adds extra depth)
    glColor3f(0.05f, 0.6f, 0.05f);
    for (float i = -1.0f; i < 1.0f; i += 0.03f) {
        float angle = (rand() % 20) - 10.0f;
        float height = ((rand() % 20) / 100.0f + 0.10f) * 0.3f;

        glBegin(GL_LINES);
        glVertex2f(i, -0.8f);  // Lower the base position for depth
        glVertex2f(i + sin(angle * M_PI / 180.0f) * height, -0.5f + cos(angle * M_PI / 180.0f) * height);
        glEnd();
    }

    /// Lighter green for the fourth layer (highlights)
    glColor3f(0.4f, 1.0f, 0.4f);
    for (float i = -1.0f; i < 1.0f; i += 0.03f) {
        float angle = (rand() % 20) - 10.0f;
        float height = ((rand() % 40) / 100.0f + 0.15f) * 0.5f;  // Reduced height by 50%

        glBegin(GL_LINES);
        glVertex2f(i, -0.5f);
        glVertex2f(i + sin(angle * M_PI / 180.0f) * height, -0.5f + cos(angle * M_PI / 180.0f) * height);
        glEnd();
    }

    /// Additional fifth layer with varied color for extra density
    glColor3f(0.2f, 0.9f, 0.2f);  // Light green with a slightly darker tint
    for (float i = -1.0f; i < 1.0f; i += 0.02f) {  // Further reduce spacing for maximum density
        float angle = (rand() % 25) - 12.5f;  // Slightly wider angle range
        float height = ((rand() % 50) / 100.0f + 0.15f) * 0.5f;

        glBegin(GL_LINES);
        glVertex2f(i, -0.5f);  // Ground level
        glVertex2f(i + sin(angle * M_PI / 180.0f) * height, -0.5f + cos(angle * M_PI / 180.0f) * height);
        glEnd();
    }
}

void drawWater() {
    // Create a gradient with smooth transitions from dark blue to light blue
    glBegin(GL_QUADS);

    // Bottom left corner (dark blue)
    glColor3f(0.0f, 0.0f, 0.5f);  // Dark blue color
    glVertex2f(-1.0f, -0.5f);

    // Bottom right corner (lighter blue)
    glColor3f(0.2f, 0.4f, 0.8f);  // Lighter blue color for the base
    glVertex2f(2.0f, -0.5f);

    // Top right corner (gradient lighter blue to simulate reflection)
    glColor3f(0.4f, 0.6f, 1.0f);  // Slightly lighter blue for the middle of the water
    glVertex2f(1.0f, -1.0f); // Adjusted for the middle section to change

    // Top left corner (dark blue for the top)
    glColor3f(0.0f, 0.0f, 0.5f);  // Dark blue color for top section
    glVertex2f(-1.0f, -1.0f);

    glEnd();
}

void drawCurvedLine() {
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the curved line
    glLineWidth(5.0f);           // Set line thickness
    glBegin(GL_LINE_STRIP);      // Use GL_LINE_STRIP for a continuous curve

    /// Double the angle range to increase the curve length by 100%
    for (float angle = 180.0f; angle <= 360.0f; angle += 0.9f) { // Extended angle range
        float x = 0.69f * cos(angle * M_PI / 180.0f);             // X coordinate for the curve
        float y = -0.71f + 0.1f * sin(angle * M_PI / 180.0f);     // Y coordinate for the curve
        glVertex2f(x, y);                                        // Add vertex to the curve
    }

    glEnd(); // End of drawing
}


    void drawBoat() {
    /// Save the current transformation state
    glPushMatrix();

    /// --- Draw the Border of the Hull (Black) ---
    glColor3f(0.0f, 0.0f, 0.0f);  // Black color for the border
    glBegin(GL_POLYGON);

    /// Number of steps for the border (same as the gradient)
    int numSteps = 50;

    /// Draw the border of the hull with a solid black color
    for (int i = 0; i <= numSteps; i++) {
        float angle = 180.0f + (180.0f * float(i) / float(numSteps)); // Angle increases from 180 to 360
        float x = 0.7f * cos(angle * M_PI / 180.0f);  // Adjusted for a smooth curve
        float y = -0.7f + 0.3f * sin(angle * M_PI / 180.0f);  // Smooth curve for hull

        glVertex2f(x, y);  // Add the vertex for this step in the border
    }

    glEnd();

    /// --- Draw the Rounded Hull with Dark Brown Gradient ---
    glColor3f(0.4f, 0.2f, 0.1f);  // Dark brown color for the hull (start color of the gradient)
    glBegin(GL_POLYGON);

    /// Interpolating the colors (from dark brown to darker brown)
    for (int i = 0; i <= numSteps; i++) {
        // Interpolate between dark brown (0.4f, 0.2f, 0.1f) and darker brown (0.3f, 0.1f, 0.05f)
        float t = float(i) / float(numSteps);  // t goes from 0 to 1
        float r = 0.4f - (0.1f * t);  // Interpolate red from dark brown (0.4) to darker brown (0.3)
        float g = 0.2f - (0.1f * t);  // Interpolate green from dark brown (0.2) to darker brown (0.1)
        float b = 0.1f - (0.05f * t);  // Interpolate blue from dark brown (0.1) to darker brown (0.05)

        // Set the current color
        glColor3f(r, g, b);

        // Calculate the vertices for the rounded hull shape
        float angle = 180.0f + (180.0f * float(i) / float(numSteps)); // Angle increases from 180 to 360
        float x = 0.7f * cos(angle * M_PI / 180.0f);  // Adjusted for a smooth curve
        float y = -0.7f + 0.3f * sin(angle * M_PI / 180.0f);  // Smooth curve for hull

        glVertex2f(x, y);  // Add the vertex for this step in the hull
    }

    glEnd();

    /// --- Add Ripples on the Water ---
    glColor3f(0.0f, 0.0f, 0.f);  // Slightly darker color for the water ripples
    // Subtle ripples with a darker water tone
    for (float x = -0.5f; x <= 0.5f; x += 0.1f) {
        glBegin(GL_LINES);
        glVertex2f(x, -0.7f);           // Starting point of the ripple
        glVertex2f(x + 0.12f, -0.78f);  // Ripple direction (50% wider)
        glEnd();
    }

    glPopMatrix();
}

float rotationAngle = 0.0f; // Global rotation angle for the blades

void windmill(float centerX, float centerY, float scale) {
    float bladeLength = 0.13f * scale;  // Adjusted for 30% larger size
    float bladeWidth = 0.05f * scale;

    glPushMatrix();
    glTranslatef(centerX, centerY, 0.0f);  // Translate to center of the windmill
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // Rotate around the center
    glTranslatef(-centerX, -centerY, 0.0f); // Undo translation for proper rotation

    // Blade 1 (Top-Right)
    glBegin(GL_POLYGON);
    glVertex2f(centerX, centerY);
    glVertex2f(centerX + bladeWidth / 2, centerY + bladeLength / 1.5f);
    glVertex2f(centerX, centerY + bladeLength);
    glVertex2f(centerX - bladeWidth / 2, centerY + bladeLength / 1.5f);
    glEnd();

    // Blade 2 (Top-Left)
    glBegin(GL_POLYGON);
    glVertex2f(centerX, centerY);
    glVertex2f(centerX - bladeLength / 1.5f, centerY + bladeWidth / 2);
    glVertex2f(centerX - bladeLength, centerY);
    glVertex2f(centerX - bladeLength / 1.5f, centerY - bladeWidth / 2);
    glEnd();

    // Blade 3 (Bottom-Left)
    glBegin(GL_POLYGON);
    glVertex2f(centerX, centerY);
    glVertex2f(centerX - bladeWidth / 2, centerY - bladeLength / 1.5f);
    glVertex2f(centerX, centerY - bladeLength);
    glVertex2f(centerX + bladeWidth / 2, centerY - bladeLength / 1.5f);
    glEnd();

    // Blade 4 (Bottom-Right)
    glBegin(GL_POLYGON);
    glVertex2f(centerX, centerY);
    glVertex2f(centerX + bladeLength / 1.5f, centerY - bladeWidth / 2);
    glVertex2f(centerX + bladeLength, centerY);
    glVertex2f(centerX + bladeLength / 1.5f, centerY + bladeWidth / 2);
    glEnd();

    glPopMatrix();
}

void drawWindmill() {
    float scale = 1.3f;  // Scale factor for blade size (30% larger)

    // First windmill (left side)
    glPushMatrix();
    glTranslatef(-0.6f, 0.0f, 0.0f);
    glColor3f(0.8f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.3f);
    glVertex2f(0.05f, -0.3f);
    glVertex2f(0.02f, 0.4f);
    glVertex2f(-0.02f, 0.4f);
    glEnd();
    glColor3f(0.4f, 0.3f, 0.4f);
    windmill(0.0f, 0.4f, scale);
    glPopMatrix();

    // Second windmill (center)
    glPushMatrix();
    glColor3f(0.8f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.3f);
    glVertex2f(0.05f, -0.3f);
    glVertex2f(0.02f, 0.4f);
    glVertex2f(-0.02f, 0.4f);
    glEnd();
    glColor3f(0.4f, 0.3f, 0.4f);
    windmill(0.0f, 0.4f, scale);
    glPopMatrix();

    // Third windmill (right side)
    glPushMatrix();
    glTranslatef(0.6f, 0.0f, 0.0f);
    glColor3f(0.8f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.3f);
    glVertex2f(0.05f, -0.3f);
    glVertex2f(0.02f, 0.4f);
    glVertex2f(-0.02f, 0.4f);
    glEnd();
    glColor3f(0.4f, 0.3f, 0.4f);
    windmill(0.0f, 0.4f, scale);
    glPopMatrix();
}
void drawSoilLine() {
    // Draw the base soil layer
    glBegin(GL_QUADS);

    // Bottom left corner (darker brown for depth)
    glColor3f(0.45f, 0.23f, 0.05f);
    glVertex2f(-1.0f, -1.0f);

    // Bottom right corner (darker brown for depth)
    glColor3f(0.45f, 0.23f, 0.05f);
    glVertex2f(1.0f, -1.0f);

    // Top right corner (lighter brown for gradient effect)
    glColor3f(0.6f, 0.35f, 0.15f);
    glVertex2f(1.0f, -0.8f);

    // Top left corner (lighter brown for gradient effect)
    glColor3f(0.6f, 0.35f, 0.15f);
    glVertex2f(-1.0f, -0.8f);

    glEnd();
    }



void drawBambooTree(float baseX, float baseY, float height, float width) {
    int segments = 6; // Number of segments in the bamboo
    float segmentHeight = height / segments;

    // Draw bamboo stalk with gradient shading
    for (int i = 0; i < segments; ++i) {
        float bottomY = baseY + i * segmentHeight;
        float topY = bottomY + segmentHeight - 0.02f;

        glBegin(GL_QUADS);
        glColor3f(0.2f + 0.02f * i, 0.7f - 0.01f * i, 0.2f); // Gradient green
        glVertex2f(baseX - width / 2, bottomY);
        glVertex2f(baseX + width / 2, bottomY);
        glColor3f(0.6f, 0.5f, 0.1f); // Dark yellow for joints
        glVertex2f(baseX + width / 2, topY);
        glVertex2f(baseX - width / 2, topY);
        glEnd();

        // Draw widened joint between segments
        glBegin(GL_LINES);
        glColor3f(0.6f, 0.5f, 0.1f); // Dark yellow for joints
        glVertex2f(baseX - width / 2 - 0.01f, topY);
        glVertex2f(baseX + width / 2 + 0.01f, topY);
        glEnd();
    }

    // Draw realistic leaves with curved shapes
    glColor3f(0.1f, 0.8f, 0.1f); // Gradient green for joints
    glBegin(GL_TRIANGLES);

    // Left leaf cluster
    glVertex2f(baseX - width / 2, baseY + height * 0.75f);
    glVertex2f(baseX - width * 1.5f, baseY + height * 0.95f);
    glVertex2f(baseX - width * 0.2f, baseY + height * 0.85f);

    glVertex2f(baseX - width / 2, baseY + height * 0.85f);
    glVertex2f(baseX - width * 1.2f, baseY + height * 1.05f);
    glVertex2f(baseX, baseY + height * 0.9f);

    // Right leaf cluster
    glVertex2f(baseX + width / 2, baseY + height * 0.75f);
    glVertex2f(baseX + width * 1.5f, baseY + height * 0.95f);
    glVertex2f(baseX + width * 0.2f, baseY + height * 0.85f);

    glVertex2f(baseX + width / 2, baseY + height * 0.85f);
    glVertex2f(baseX + width * 1.2f, baseY + height * 1.05f);
    glVertex2f(baseX, baseY + height * 0.9f);

    glEnd();
}

// Function to draw multiple bamboo trees in a row
void drawBambooForest() {
    drawBambooTree(-0.9f, -0.8f, 0.5f, 0.02f); // Left bamboo tree
    drawBambooTree(-0.9f, -0.5f, 0.5f, 0.02f); // Left bamboo tree

    drawBambooTree(-0.4f, -0.8f, 0.5f, 0.03f); // Left bamboo tree
    drawBambooTree(-0.4f, -0.5f, 0.5f, 0.03f); // Left bamboo tree

    drawBambooTree(-0.5f, -0.8f, 0.6f, 0.02f); // Middle bamboo tree
    drawBambooTree(-0.5f, -0.5f, 0.6f, 0.02f); // Middle bamboo tree

    drawBambooTree(-0.3f, -0.8f, 0.6f, 0.02f); // Middle bamboo tree
    drawBambooTree(-0.3f, -0.5f, 0.6f, 0.025f); // Middle bamboo tree

    drawBambooTree(-0.1f, -0.8f, 0.6f, 0.02f); // Right bamboo tree
    drawBambooTree(-0.1f, -0.5f, 0.6f, 0.026f); // Right bamboo tree
}
// Function to draw a circle (used for leaves)
void drawCircle1(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for (float angle = 0.0; angle <= 2 * M_PI; angle += 0.1) {
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

// Function to draw the tree trunk
void drawTrunk(float x, float y, float width, float height) {
    glColor3f(0.5f, 0.25f, 0.1f); // Brown color for the trunk
    glBegin(GL_QUADS);
    glVertex2f(x - width / 2, y);         // Bottom left
    glVertex2f(x + width / 2, y);         // Bottom right
    glVertex2f(x + width / 2, y + height); // Top right
    glVertex2f(x - width / 2, y + height); // Top left
    glEnd();
}

void drawBranch(float x, float y, float angle, float length, float width) {
    glPushMatrix();
    glTranslatef(x, y, 0);  // Translate to the current branch position
    glRotatef(angle, 0, 0, 1);  // Rotate the branch

    glColor3f(0.5f, 0.25f, 0.1f);  // Dark brown color for the branch

    // Draw a narrow, tapered branch
    glBegin(GL_QUADS);

    // Start of the branch (thinner at the start)
    glVertex2f(0.0f, 0.0f);
    // End of the branch (tapering effect, width decreases along the length)
    glVertex2f(length, 0.01f);
    // End width of the branch (same width at the far end)
    glVertex2f(length, width * 0.5f);  // Making the branch a little thinner as it extends
    // Start width of the branch (wider near the base)
    glVertex2f(0.0f, width * 0.5f);   // Making the branch wider at the base
    glEnd();

    glPopMatrix();
}


void drawLeaves(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);

    // Central vein (lighter green)
    glColor3f(0.2f, 0.8f, 0.2f); // Light green color for the center of the leaf
    glVertex2f(x, y);  // Center of the leaf

    // Draw a gradient effect by adjusting the color as we go around the leaf
    for (float angle = 0.0f; angle <= 2 * M_PI; angle += 0.1f) {
        // Simulate a leaf's natural gradient
        float green = 0.3f + 0.5f * cos(angle); // A smooth gradient from lighter green in the center to darker green at the edges
        float red = 0.2f + 0.1f * sin(angle);  // Slight reddish hue for more realism
        glColor3f(red, green, 0.2f); // Green + red tint for a more natural leaf color

        // Adjust the coordinates to create an asymmetrical leaf shape (slightly elongated and pointed at the tip)
        float adjustedRadius = radius * (1 + 0.2f * sin(angle));  // Slightly modify radius to simulate leaf variation
        glVertex2f(x + adjustedRadius * cos(angle), y + radius * sin(angle));
    }

    glEnd();
}


// Function to draw the tree with trunk, branches, and leaves
void drawTree(float x, float y, float trunkHeight, float trunkWidth) {
    // Adjust the x position to move the tree to the left (80% left)
    x -= 0.8 * trunkWidth; // Move the tree left by 80% of the trunk width

    // Draw the trunk
    drawTrunk(x, y, trunkWidth, trunkHeight);

    // Draw branches without randomness
    drawBranch(x, y + trunkHeight, 30, 0.5 * trunkHeight, 0.05);
    drawBranch(x, y + trunkHeight, -30, 0.5 * trunkHeight, 0.05);

    drawBranch(x, y + trunkHeight, 60, 0.4 * trunkHeight, 0.04);
    drawBranch(x, y + trunkHeight, -60, 0.4 * trunkHeight, 0.04);

    drawBranch(x, y + trunkHeight, 90, 0.3 * trunkHeight, 0.03);
    drawBranch(x, y + trunkHeight, -90, 0.3 * trunkHeight, 0.03);

    // Draw leaves at the ends of the branches
    drawLeaves(x + 0.5 * trunkHeight * cos(30 * M_PI / 180), y + trunkHeight + 0.5 * trunkHeight * sin(30 * M_PI / 180), 0.1);
    drawLeaves(x - 0.5 * trunkHeight * cos(30 * M_PI / 180), y + trunkHeight + 0.5 * trunkHeight * sin(30 * M_PI / 180), 0.1);

    drawLeaves(x + 0.4 * trunkHeight * cos(60 * M_PI / 180), y + trunkHeight + 0.4 * trunkHeight * sin(60 * M_PI / 180), 0.1);
    drawLeaves(x - 0.4 * trunkHeight * cos(60 * M_PI / 180), y + trunkHeight + 0.4 * trunkHeight * sin(60 * M_PI / 180), 0.1);

    drawLeaves(x + 0.3 * trunkHeight * cos(90 * M_PI / 180), y + trunkHeight + 0.3 * trunkHeight * sin(90 * M_PI / 180), 0.1);
    drawLeaves(x - 0.3 * trunkHeight * cos(90 * M_PI / 180), y + trunkHeight + 0.3 * trunkHeight * sin(90 * M_PI / 180), 0.1);
}


/// Function to draw the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen buffer
    drawSun();
    // Animated clouds
    drawCloud(-0.6, 0.7, 0.1);
    drawCloud(-0.3, 0.8, 0.15);
    drawCloud(0.2, 0.75, 0.12);
    drawCloud(0.6, 0.85, 0.1);
    drawMountains();
    drawVillageSoilRoad();
    drawTree(0.80, -0.4, 0.5, 0.1); // Draw a tree at the origin with specified height and width
    drawWindmill();
    drawNewHouse();
    drawTree(-0.80, -0.5, 0.4, 0.1); // Draw a tree at the origin with specified height and width

    drawVillageHouse(); // Corrected placement of this function
    drawGrass();
    drawWater();
    drawSoilLine();
    drawBambooForest();
    drawBoat();
    drawCurvedLine();
    glutSwapBuffers(); // Perform double buffering only once
}

/// Function to update the scene
void update(int value) {
    // Update cloud movement
    cloudOffset += 0.01f; // Increment the horizontal offset
    if (cloudOffset > 2.0f) {
        cloudOffset = -2.0f; // Reset offset when clouds move off-screen
    }

    rotationAngle += 1.0f; // Decreased rotation speed
    if (rotationAngle > 360.0f) {
        rotationAngle -= 360.0f; // Keep the angle within 360 degrees
    }

    glutPostRedisplay();         // Mark the window for redrawing
    glutTimerFunc(33, update, 0); // Call update every 33 ms (30 FPS)
}
/// Function to initialize OpenGL settings
void initOpenGL() {
    glClearColor(0.7, 0.9, 1.0, 1.0); // Set background to light sky blue
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2.1, 2.1, -1, 1);  // Set up orthographic projection
    glClearColor(0.7, 0.9, 1.0, 1.0); // Set background to light sky blue
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}
/// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);                      // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Enable double buffering and RGB mode
    glutInitWindowSize(800, 600);               // Set the window size
    glutInitWindowPosition(100, 100);           // Set the window position
    glutCreateWindow("Mountain Scene with Green Gradient"); // Create the window
    initOpenGL();                               // Initialize OpenGL settings
    glutDisplayFunc(display);                   // Register the display callback
    glutTimerFunc(33, update, 0);               // Start the update function (30 FPS)
    glutMainLoop();                             // Enter the main loop
    return 0;
}
