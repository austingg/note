# -*- coding:utf-8 -*-
import scrapy
from tutorial.items import BaiDuTieBaItem


class BaiduTieBaSpider(scrapy.spiders.Spider):
    name = 'baidutieba'
    start_urls = ['http://tieba.baidu.com/p/2235513502?see_lz=1&pn=%d' % i for i in range(1, 30)]

    image_names = {}

    def parse(self, response):

        item = BaiDuTieBaItem()
        item['image_urls'] = response.xpath("//img[@class='BDE_Image']/@src").extract()
        for index, value in enumerate(item['image_urls']):
            number = self.start_urls.index(response.url) * len(item['image_urls']) + index
            self.image_names[value] = 'full/%04d.jpg' % number
            yield item


