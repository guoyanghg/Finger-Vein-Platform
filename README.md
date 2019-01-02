# Finger-Vein-Platform
This project consists of two modules, "Main Platform" and "Demo Platform". If you are interested in the Main Platform, please contact with [authors.](#Authors) 
## Main Platform
### Algorithm Execution Module

The algorithm execution module consists of two modes, namely single and double mode.

1.1 Single Mode

By importing a single finger vein infrared image through the file menu, you can see the visualization effect of algorithms. The four windows of the platform (from top left to bottom right) display the original image, the image after cutting, the image after zooming by ROI and the feature image respectively. In addition, you can right-click on each image to process and switch.

1.2 Double Mode

You can use the `edit` button to switch to the Double mode. Then, you need to import two finger vein infrared images from the `file` menu. The four windows of the platform (from top left to bottom right)display the original image of the first image, the original image of the second image, and the features of the first image and second image respectively. Unlike the Single Mode, the details, such as ROI extraction, are hidden. In addition, it is crucial that the double image mode provides matching function and give matching scores that can be used in comparing the algorithm.

### Database Processing Module

The database processing module consists of `algorithm running unit` and `batch processing unit of raw data`.

2.1 Algorithm Execution

You can use all the algorithm in Algorithm Execution Module, and additionally Database Processing Module provides a PBBM (Personalized Best Bit Map) algorithm. Click on "Database Processing" button and the corresponding interface will appear. Fill in the parameters according to the instructions to complete the algorithm execution on the database. At the end of the execution, you can get FAR, FRR, ROC (Receiver Operating Characteristic) curves and EER. 

2.2 Batch Processing of the Raw Data

This provides batch processing of the original database. Clicking on the "Batch Cut" button will pop up the corresponding interactive interface.

### Interface Auxiliary Module

The interface auxiliary module provides some convenient functions in consideration of improving interactivity of the platform.

3.1 Window Control

The horizontal bar on the edge of the window can be dragged to adjust the size of the display window. Double-clicking the display window will extend the window to full screen. Double-clicking the window again will restore the same size to the four windows. In the widow on the right side, you can see some useful information, such as the size of the image in each display window. The output window below is for displaying various operational information such as scores.


## Demo Platform

You can find the installation instructions in the `Demo Platform` folder.


## Authors
* Project Leader: Yang Guo 

* guoyanghg@163.com

* Main Member: Yongqiang Jiang 

* iamxiaoqiangzi@gmail.com

* Zeyan Kang & Yilin Wen

## Lisence
National Copyright Administration of the PRC

Computer Software Copyright Registration Certificate

Registration No.：2016SR126579
