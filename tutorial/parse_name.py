# encoding:utf-8
import os
if __name__ == "__main__":
    with open("star.csv") as f:
    	with open('stars.txt', 'w') as outfile:
	        for star in f.readlines():
	            star_name = star.strip().split(",")
	            outfile.write("%s\n" % star_name[0])