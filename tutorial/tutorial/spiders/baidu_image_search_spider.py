# -*- coding:utf-8 -*-
import scrapy
from tutorial.items import BaiDuImageSearchItem
import urllib
import json


class BaiduImageSearchSpider(scrapy.spiders.Spider):
    name = 'baidu_image_search'
    image_names = {}

    def __init__(self, keyword='足球', *args, **kwargs):
        super(BaiduImageSearchSpider, self).__init__(*args, **kwargs)

        keyword = keyword.decode('gbk').encode('utf-8')
        kw = urllib.quote(keyword)
        print keyword, kw
        self.start_urls = [
            'http://image.baidu.com/search/avatarjson?tn=resultjsonavatarnew&ie=utf-8&word=%s&pn=%d&rn=30&itg=0&z=0&fr=&width=&height=&lm=-1&ic=0&s=0&st=-1&gsm=350700003c' % (kw, i) for i in range(1, 2701, 30)]
        print self.start_urls

    def parse(self, response):
        item = BaiDuImageSearchItem()
        json_response = json.loads(response.body_as_unicode())
        item['image_urls'] = [img['objURL'] for img in json_response['imgs']]
        for index, value in enumerate(item['image_urls']):
            number = self.start_urls.index(response.url) * len(item['image_urls']) + index
            self.image_names[value] = 'full/%04d.jpg' % number
        yield item

