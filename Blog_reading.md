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

