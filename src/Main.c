#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define SCREEN_WIDTH 	(80)
#define SCREEN_HEIGHT 	(22)

int main() {
    float angleX = 0;
    float angleZ = 0;

    const float R = 2.0;
    const float r = 1.0;
    const float cameraDistance = 4.0;
    const float scale = 30.0;

    const float aspectRatio = 0.5;

    float zbuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
    char screen[SCREEN_WIDTH * SCREEN_HEIGHT];

    while (1) {
        memset(screen, ' ', sizeof(screen));
        memset(zbuffer, 0, sizeof(zbuffer));

        for (float theta = 0; theta < 2 * M_PI; theta += 0.07) {
            for (float phi = 0; phi < 2 * M_PI; phi += 0.02) {
                float circleX = R + r * cos(theta);
                float circleZ = r * sin(theta);

                float x = circleX * cos(phi);
                float y = circleX * sin(phi);
                float z = circleZ;

                float nx = cos(theta) * cos(phi);
                float ny = cos(theta) * sin(phi);
                float nz = sin(theta);

                float y1 = y * cos(angleX) - z * sin(angleX);
                float z1 = y * sin(angleX) + z * cos(angleX);

                float ny1 = ny * cos(angleX) - nz * sin(angleX);
                float nz1 = ny * sin(angleX) + nz * cos(angleX);

                float x2 = x * cos(angleZ) - y1 * sin(angleZ);
                float y2 = x * sin(angleZ) + y1 * cos(angleZ);

                float nx2 = nx * cos(angleZ) - ny1 * sin(angleZ);
                float ny2 = nx * sin(angleZ) + ny1 * cos(angleZ);

                float ooz = 1 / (z1 + cameraDistance);

                int xp = SCREEN_WIDTH / 2 + scale * ooz * x2;
                int yp = SCREEN_HEIGHT / 2 - scale * ooz * y2 * aspectRatio;

                int idx = xp + SCREEN_WIDTH * yp;

                float light = nx2 * 0 + ny2 * 1 + nz1 * -1;

                if (xp >= 0 && xp < SCREEN_WIDTH &&
                    yp >= 0 && yp < SCREEN_HEIGHT &&
                    ooz > zbuffer[idx]) {

                    zbuffer[idx] = ooz;

                    const char *shades = ".,-~:;=!*#$@";
                    int shadeIndex = (int)((light + 1) * 5.5);

                    if (shadeIndex < 0) shadeIndex = 0;
                    if (shadeIndex > 11) shadeIndex = 11;

                    screen[idx] = shades[shadeIndex];
                }
            }
        }

        printf("\x1b[H");
        for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
            putchar(i % SCREEN_WIDTH ? screen[i] : '\n');
        }

        angleX += 0.04;
        angleZ += 0.02;

        usleep(30000);
    }
}