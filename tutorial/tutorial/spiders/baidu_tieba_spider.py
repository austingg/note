# -*- coding:utf-8 -*-
import scrapy
from tutorial.items import BaiDuTieBaItem


class BaiduTieBaSpider(scrapy.spiders.Spider):
    name = 'baidutieba'
    # start_urls = ['http://tieba.baidu.com/p/2235516502?see_lz=1&pn=%d' % i for i in range(1, 30)]
    start_urls = ['http://image.baidu.com/search/index?tn=baiduimage&word=花朵&pn=%d&rn=30' % i*30 for i in range(1, 18)]
    image_names = {}

    def parse(self, response):
        item = BaiDuTieBaItem()
        # item['image_urls'] = response.xpath("//img[@class='BDE_Image']/@src").extract()
        item['image_urls'] = response.xpath(u"//img[@class='main_img img-hover']/src").extract()
        # print len(item['image_urls'])
        for index, value in enumerate(item['image_urls']):
            number = self.start_urls.index(response.url) * len(item['image_urls']) + index
            self.image_names[value] = 'full/%04d.jpg' % number
        yield item

