import cv2

# Load the image
image = cv2.imread('cafe.jpg')

# Convert the image to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)

# Specify the parameters for HOG descriptors
win_size = (64, 64)  
block_size = (16, 16)  
block_stride = (8, 8)  
cell_size = (8, 8)  
nbins = 9 

# Set the parameters of the HOG descriptor using the variables defined above
hog = cv2.HOGDescriptor(win_size, block_size, block_stride, cell_size, nbins)

#Extract features
hog_features = hog.compute(gray)

# Flatten the HOG features
hog_features = hog_features.flatten()

print(hog_features)