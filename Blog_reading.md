Blob Reading
=============
# Learning from Imbalanced Classes 
1. If you're fresh from a machine learning course, chances are most of the datasets you used were fairly easy. 
2. balanced dataset: meaning there were approximately the same number of examples of each class.
3. Research on imblanced classes often considers imblanced to mean a minority class of 10% to 20%. 
4. Convetional algorithms are often biased towards the majority class because their loss functions attempt to opimize quantities such as error rate, not taking the data distribution into consideration.
5. These are listed approximately in order of effort:
    * Do nothing. Sometimes you get lucky and nothing needs to be done. You can train on the so-called natural distribution and sometimes it works without need for modification.
    * Balanced the training set in some way:
        - Oversample the minority class
        - Undersample the majority class
        - Synthesize new minority class
    * Throw away minority examples and switch to an anomaly detection framework
    * At the algorithm level, or after it:
        - Adjust the class weight (misclassication costs)
        - Adjust the decision threshold
        - Modify an existing algorithm to be more sensitive to rare classes.



# Understanding Aesthetics with Deep Learning[link](https://devblogs.nvidia.com/parallelforall/understanding-aesthetics-deep-learning/)
1. Why not use a classifier to separate images as aesthetic vs. not. May be the idea is to also find similar images to high quality images using the embedding and allow image search.
    * Often there is no correct classification if an image is aesthetics or not, and bucketing it into a class is non-trival. Further, our understanding of aesthetics is perceptual and relative, so this has to be approaches as a ranking problem, rather than a classification problem. Hence the motivation for using implicit regression/ranking framework. This is true for other cases, like image similarity, where the boudaries are fuzzy. 
2. dataset
    * Unlike in image classification, understanding and appreciating aesthetics is quite an expert-level task. Our researchers and curators, who are award winning photographers, collaborated deeply to create out training data.
    * When collecting the positive classes of our training set we set very high standards. We selected only pictures that communicate strong stories with strong composition, and that were shot with technical mastery.
    * The advantage of convolutional neural networks is that they's purely data-driven and give us the luxury of not having to hand-specify features, which allows us to work in a non-reductionist framework.
    * Over 100,000 images were categorized. 
    * Not every triplet contributes equally to either the convergence or the finaly expressiblity of our models. The connection of aesthetics with the story being told is often subtle and hard to define, but nevertheless plays an important role. A similariry measure based on keyword detection gives us a good prior in sampling our triplets. We use more than 60 million such triplets for training the final model over 20,000 iterations, we trained our networks using a single NVIDIA Tesla K40 card, which converged in 2 to 3 days.
3. During training, we pass each image of the triplet through a separate convolutional nerual network. We experimented with vaious CNN architectures. An 11 layer Oxford model was sufficient for good convergence and performance. We enforced the weights of the three networks to be the same, since we found this made the newworks converge easier. Further, at the run time, this allowed us to used a single convolutional network, thus keeping our run time cost low.
4. Automatic image tagging thecnologies from companies like EyeEm, flickr, and Clarifai are quickly approaching maturity and helping to tell the stories behind photographs by indexing or tagging them to make them discoverable.
5. The question then to ask is what do the master photographers' images have in common, and what separates them from the amateur images? While it's difficult for a computer to answer a philosophical question, if we express the question in mathematical space in which the distance between the two images that are aesthecially pleasing is the less than the distance between an sesthetically pleasing on and a mediocre one. 
6. A much stronger strategy is to transform the image via various mathematical operators into a set of measurements called image features that summarize the visual information that is relevant to our solutoin, and disregard irrelevant information. Finding a good feature representation manually is hard, but in the recent past CNN have exhibited tremendous success at automatically determining relevant features directly from training data.