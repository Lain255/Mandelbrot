#include <stdio.h>

float mandelBrot(float a, float b, int n)
{
    float x = 0;
    float y = 0;

    float temp;

    for (int i = 0; i < n; i++)
    {
        temp = x;
        x = x * x - y * y + a;
        y = 2 * temp * y + b;
    }
    return x*x + y*y;
}

int main()
{
    const int w = 1000;
    const int h = 1000;

    const float mandelw = 3;
    const float mandelh = 3;

    FILE* file = fopen("Mandelbrot.ppm", "w");
    fprintf(file, "P3\n");
    fprintf(file, "%i %i\n", w, h);
    fprintf(file, "255\n");

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            const float clip = 10;
            float x = mandelw * ((float)j/w - 0.7);
            float y = mandelh * ((float)i/h - 0.5);
            float value = mandelBrot(x, y, 100);
            float clipped = value < clip ? value : clip;
            int out = (clipped / clip) * 255;

            fprintf(file, "%i %i %i ", out, out, out);
        }
    }
    
    fclose(file);
    return 0;
}