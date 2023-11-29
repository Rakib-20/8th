import cv2
 
# Load the image
img = cv2.imread('cafe.jpg')

# Convert to grayscale
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Detect edges using Canny method
edges = cv2.Canny(gray, threshold1=100, threshold2=200)

# Flatten the edge features
edges = edges.flatten()

print(edges)