public static float cubeInterpolation(float a, float b, float x)
{
	if(x < a) return 0;
	if (x > = b) {
		return 1;
	}
	x = (x - a)/(b - a);
	return x*x*(3-2*x);
}

public static void fastBlur(){

}

private BufferedImage addSaltAndPepperNoise(BufferedImage src, BufferedImage dst)
{
	int width = src.getWidth();
	int height = src.getHeight();

	int[] inPixels = new int[width * height];
	getRGB(src, 0, 0, width, height, inPixels);

	int index = 0;
	int size = (int)(inPixels.length*(1-SNR));

	for (int i = 0; i < size; i++) {
		int row = (int)(Math.random()*(double)height);
		int col = (int)(Math.random()*(double)width);

		index = row*width + col;
		inPixels[index] = (255 << 24)|(255<<16)|(255<<8)|255;
	}

	setRGB(dst, 0, 0, width, height, inPixels);

	return dst;
}


import java.awt.image.BufferedImage;

public class SepiaToneFilter extends AbstractBufferedImageOp{

	@Override
	public BufferedImage filter(BufferedImage src, BufferedImage dst){
		int width = src.getWidth();
		int height = src.getHeight();

		if (dst == null) {
			dst = createCopatibleDestImage(src, null);
		}

		int[] inPixels = new int[width*height];
		int[] outPixels = new int[width*height];

		getRGB(src, 0, 0, width, height, inPixels);

		int index = 0;
		for (int row = 0; row < height; row++) {
			int ta = 0, tr = 0, tg = 0, tb = 0;
			for (int col = 0; col < width; col++) {
				index = row*width+col;

				ta = (inPixels[index]>>24)&0xFF;
				tr = (inPixels[index]>>16)&0xFF;
				tg = (inPixels[index]>>8)&0xFF;
				tb = (inPixels[index])&0xFF;

				int fr = (int)colorBlend(noise(), tr*0.393+tg*0.769+tb*0.189, tr);
				int fg = (int)colorBlend(noise(), tr*0.349+tg*0.686+tb*0.168, tg);
				int fb = (int)colorBlend(noise(), tr*0.272+tg*0.534+tb*0.131, tb);

				outPixels[index] = (ta<<24)|(clamp(fr)<<16)|(clamp(fg)<<8)|clamp(fb);
			}

		}

		setRGB(dst, 0, 0, width, height, outPixels);
		return dst;
	}

	private double noise(){
		return Math.random()*0.5+0.5;
	}

	private double colorBlend(double scale, double src, double dst){
		return scale*dst + (1.0-scale)*src;
	}

	private static int clamp(int c){
		return c > 255 ? 255 : (c < 0) ? 0 : c;
	}

	public String toString(){
		return "Sepia Tone effect - Effect from photoshop App";
	}
}


double generateGaussianNoise()
{
	static bool hasSpace = fasle;
	static double rand1, rand2;

	if(hasSpace)
	{
		hasSpace = false;
		return sqrt(rand1)*sin(rand2);
	}

	hasSpace = true;
	rand1 = rand()/(double)RAND_MAX);
	if (rand1 < 1e-10) {
		rand1 = 1e-10;
	}
	rand1 = -2*log(rand1);
	rand2 = (rand())/(double)RAND_MAX*TWO_PI;

	return sqrt(rand1)*cos(rand2);
}