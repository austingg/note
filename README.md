note
====

every day aquired diary


# Structured forests for fast edge detection
This module contains implementations of modern strctured edge detection algorithm, i.e. algorithm which somehow takes into account pixel affinites in natural images.

`class structedEdgeDetection : public algorithm`

##Extended Image Processing
*Structured forests for fast edge detection
*Domain Transform filter
*Guided Filter
*Adaptive Manifold filter
*Joint Bilateral filter
*Superpixels 

##Optimization Algorithms

The algorithms in this section minimize or maximize function value within specified constrains or without any constrains.

solveLP
Downhill
conjugate gradient method


##ColorMap
The human perception isn't built for observing fine changes in grayscale images. Human eyes are more senstive to observing changes between colors, so you often need to recolor your grayscale images to get a clue about them. OpenCv now comes with vairous colormaps to enhance the visualization in your computer vision application.

`applyColormap(InputArray src, OutputArray dst, int colormap)`


##White Balance
**色温**


###Java 数字图像处理与特效
* java.awt.BufferedImage
* 图像处理中错误扩散，抖动算法在数字半调(halftone)中有着重要应用。
* 坚持研究图像已经两年额，坚持每月写四篇博文。发现自己学东西越来越快，主要得益于自己在图像算法方面的知识积累，以及数据可视化。我坚信帮助别人，快乐自己。


Markdown 语言简洁
=================


#标题一
##标题二

#列表
* a
* b

1. a
2. b
3. c

#引用：
> stay hungry, stdy foolish

#图片与链接

[Baidu](http://www.baidu.com)

![Mou icon](http://www.baidu.com/img/bd_logo1.png)

##粗体与斜体

##代码框

##分割线


#Usual Image Filter
* Pencil Sketch
* OilPainting
* Cartoon
* Sepia Tone Effect
* Half Tone blend
* Wave method: (本质上) Image warping
* Image edge fading effect
* Motion blur (linear convolution) effect with specified angle!
* salt and pepper, gaussian nosie

#Usual Image Opeartion
* Fast Rotation method
* Fast Scaling method

#Basic Image Processing Application
* Rice Counting


# Why Jave need Interface?  (as soon as I get my new desktop)

# Paint Engine Principle of TexturePaint


# ImageShop vs. Gloomyfish

# ToDo
* Java 2D
* UML

# 数值计算与符号计算

# cvx: standford convex programming system

> 计算机的回复往往是“你丫能不能说机话！” 这是因为计算机无法进行抽象思维，它不懂重建，去噪、清晰这些复杂的概念。
> 它唯一会的东西就是加减乘除这样的基本运算，你只能使用正确的计算语句让它去执行对应的基本预算，因此就需要首先把去噪问题转化成一个数学问题，一个函数求解问题。。
> 合理的目标函数是最优化第一个需要精心考虑的问题，需要直觉和理性；而如何求解目标函数，则是一个数学算法问题。二者都是数学家和工程师大显身手的地方。
> 
>  目前人们已经研究出一堆学习模型：神经网络、支持向量机、AdaBoost、随机森林、隐马尔科夫链。卷积神经网络。他们的结构差异很大，但是共同点都是拥有一堆参数，等着你喂给他们数据供它学习。这些模型的学习也需要一个目标函数：让模型的分类错误率尽量小。为了达到目的，模型的训练往往首先给参数附上随机初值，然后用各种下降法来寻找能让分类错误率更小的参数设置，梯度下降、牛顿法、共轭梯度法和LM法都是常见的方法。随着研究的深入，问题也越来越多，比如下降法往往只能保证目标函数的局部极小值，找不到全局最小值，怎么办呢。答案是不要一味下降，也适当爬爬山，说不定就能跳出小水沟（局部极小值）找到真正的深井（全局极小值），这种算法就模拟退火。也可以增大搜索范围，让一群蚂蚁（蚁群算法）或者鸟儿（粒子群算法）一齐搜索，或者让参数巧妙地随机改变（遗传算法）。
>  那么多模型，到底改选哪个？研究者又发现一个定理“天下没有免费的午餐”，意思是没有一个模型一直比其他模型好，对于不同类型的数据，必须通过实验才能发现哪种学习模型更适合。机器学习领域也就成为学术灌水严重的领域之一——换模型、调参数就能发文章。

#二次优化与最小二乘的关系 


> 最小二乘问题是回归分析，最优控制，参数估计等问题的基础，具有一系列统计方面的解释。例如向量的最大似然估计，以及够高斯测量误差影响的线性测量。识别一个优化问题是最小二乘问题比较直观，只需要验证目标函数是一个二次函数（并验证相关的二次函数是半正定的）。此外，还有一些常用的方法增加最小二乘问题的灵活性，如加权最小二乘，以及最小二乘的正则化。
> 最小二乘的正则化是指在代价函数中加入额外的项。额外项是指将变量的平法和与一个正的乘数银子相乘当上式第一项不能很好的实现最小化时，额外项可以对较大的变量值起到惩罚作用，进而得到更敏感的解决方案。正则化的方法往往用在统计估计中，尤其是在当已知待估计的变量服从预先的分布的情况下。


# 范数(norm) 
> 范数，是具有“长度”概念的函数。在泛函分析中，范数是一种定义在赋范线性空间中的函数，满足相应条件后的函数都可以被称为范数。

# Box-Muller变换
是产生随机数的一种方法。算法的隐含原理非常深奥，但结果却相当简单。它一般是要得到服从正态分布的随机数，基本思想是先得到服从均匀分布的随机数，再降服从均匀分布的随机数转变为正态分布。 