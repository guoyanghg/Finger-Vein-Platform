# Finger-Vein-Platform
This project consists of two modules, "Main Platform" and "Demo Platform".
## Main Platform
### Algorithm Execution Module

The algorithm execution module is divided into two modes, namely single and double mode.

1.1 Single Mode

By importing a single finger vein infrared image through the file menu, the visualization effect of internal sealing and external import algorithms can be displayed. The four windows of the platform (from top left to bottom right) display the original image, the image and edge after cutting, the image after zooming by ROI and the feature image, respectively. In addition, you can right-click on each image to process and switch, or click the quality evaluation button to extract the gradient and of the ROI.

1.2 Double Mode

Switch to double mode in the edit button and all operations will be cleared. Then, two finger vein infrared images are imported from the file menu The four windows of the platform (from top left to bottom right)display the original image of the first image, the original image of the second image, and the features of the first image and second image, respectively. Unlike single image processing, the details, such as ROI extraction, are hidden, and the right-click window still has the corresponding function in the single image mode. It is crucial that the double image mode provides a matching function and a display of matching scores that can be used in testing the algorithm for comparison.

### Database Processing Module

The database processing module consists of algorithm running unit and batch processing unit of original data.

2.1 Algorithm Operation

The database processing module has the same algorithm as the algorithm execution module, and additionally provides a PBBM (Personalized Best Bit Map) algorithm. Click on "Database Processing" button and the corresponding interactive interface will appear. Fill in the parameters according to the instructions to complete the algorithm execution on the database. At the end of the execution, generate FAR, FRR and ROC (Receiver Operating Characteristic) curves and EER. 

2.2 Batch Processing of the Raw Data

This provides batch processing of the original database. Clicking on the "Batch Cut" button will pop up the corresponding interactive interface.

### Interface Auxiliary Module

The interface auxiliary module provides some convenient functions in consideration of the interactivity of the platform.

3.1 Window Control

The horizontal bar on the edge of the window can be dragged to adjust the size of the display window. Double-clicking the display window will extend the window to full screen. Double-clicking the window again will restore the same size to the four windows. In the property view on the right, you can display attribute information, such as the size of the image in each display window. The output window below is for displaying various operational information and calculating scores.

3.2 Additional Functions

The image processing function has been mentioned in the beginning of the algorithm execution module.

## Demo Platform

This part performs the demonstration of "acquiring images from outside-->building libraries-->matching", and needs to cooperate with external collection devices. You can find the installation instructions in the xxx folder.


## Authors
* Project leader: Yang Guo 

* guoyanghg@163.com

* Main Member: Yongqiang Jiang 

* iamxiaoqiangzi@gmail.com

* Zeyan Kang & Yilin Wen

## Lisence
National Copyright Administration of the PRC

Computer Software Copyright Registration Certificate

Registration No.：2016SR126579
