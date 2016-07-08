# encoding: utf-8
import os
if __name__ == "__main__":
    with open("star.csv") as f:
        for star in f.readlines():
            star_name = star.strip().split(",")
            for n in star_name:
                if n != '':
                    command = "scrapy crawl baidu_image_search -a keyword=%s -s IMAGES_STORE=E:\\stars\\%s" \
                            % (n, star_name[0])
                    os.system(command)
