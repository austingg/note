#OpenRaster
- is a file format proposed for the common exchange of layered images between raster graphics editors. It is meant as a replacement for the later versions of the Adobe PSD format. OpenRaster is still in development and so fa is supported by a few program.
- The Adobe Photoshop PSD file format was widely used as a cross-qpplication file format for layered images. Adobe allowed this by releasing the format's sepcification publicly. In 2006 Adobe changed license to only grant acess to adn used of the specifications and documentaion. In response to these restrictions, the OpenRaster format was proposed.

#Graph cut
As applied in the field of computer vision, graph cuts can be employed to efficiently solve a wide variety of low-level computer vision problems, such as as image smoothing, the stereo sorrespndence problem, and many other computer vision problems that can be formulated in terms of energy minimization.Such energy minimization problems can be reduced to instances of the maxium flow problem in a graph. Under most formulations of such problems in computer vision, the minimum energy solution corresponds to the maximum a posteriori estimate of a solution. Although many computer vision algorithms involve cutting a graph(e.g., normalized cuts), the term "graph cuts" is applied specifically to those models which employ a max-flow/min-cut optimization(other graph cutting algorithms may be considered as graph partitioning algorithms.)

"Binary" problems(such as denosing a binary a image) can be solved exactly using this apporach; problems where pixels can be labeled with more than two different labels (such as stereo correspondenc, or denoising of a grayscale image) cannot be solved exactly, but solutions produced are usually near the global optimum.

#Image blending and composition
The landmark paper by Thomas Porter and Tom Duff, Who worked for Lucasfilm, defined the algebra of compositing and developed the twelve "Porter Duff" opeartors. These operators control the results of mixing the four sub-pixel regions formed by the overlapping of graphical objects that have an alpha or pixel coverage channel/value. The operators use all practical combinations of four regions. 

There are 12 basic Porter Duff opeartors, satisfying all possible combinations of source and destination.

For example, in source over, the possible contribution of source is full(1) and the possible contribution of destination is whatever is remaning (1 - alpha s). This is modified by the coverage of source and destination to give the equation for the final coverage of the pixel.

co = as * Fa *CS + ab * Fb * Cb

The fractional terms Fa and Fb are defined for each operator and specify the fraction of the shapes that may contribute to the final pixel value.

# Blending 
Blending is the aspect of compositing that calculates the mixing of colors where the source element and backdrop overlap.(same size)

Conceptually, the colors in the source element are blending in place with backdrop. After blending the modified source element is composited with bbackdrop. In practice, this is usually all perfermed in on step.

The blending calculations must not used pre-multiplied color values.


The result of the mixing function is modulated by the backdrop alpha. A fully opaque allows the minxing funciton to be fully realized. A transparent backdrop will cause the final result to be a weighted average between the source color and mixed color with the weight control by the backdrop alpha. The  value of the new color becomes:

Cr = (1 - ab) * cs + ab*B(Cb, Cs)

With :
* Cr: the result color
* B: the formula that does the blending
* Cs: the source color
* Cb: the backdrop color
* ab: the backdrop alpha

#Digital Compositing

In 1984, Porter and Duff wrote a paper which has become a classic. They were interested in what happens when digital images are overlayed in various ways, a process called image compositing. Digital compositing has becom increasingly important in film and televsion post-production work. A compositor thus sits at the core of most image manipulation pipelines.

Compositing pre-dates computers. In computer graphics, it is very commom to represent colours with RGB values. Typically each of these colour "channels" requires 8 bits on a PC (12-16 bits or floating point for professional applicaitons). Porter and Duff descirbed the use of a fourth channel, which they called alpha, to represent the opacity of the colour. An alpha value of 255 represents completely opaque while a value of zeros represents completely clarity. They used RGBA to indicate the four channel model. Of course the colouration and lighting generally might need adjusting, to get the two components to look like they go together, but we can use other tools to do that. Basically, we have re-invented cut-and-paste; but there is more to come.
