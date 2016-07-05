# -*- coding:utf-8 -*-
import scrapy
from tutorial.items import BaiDuTieBaItem
import urllib
import json


class BaiduTieBaSpider(scrapy.spiders.Spider):
    name = 'baidutieba'
    # start_urls = ['http://tieba.baidu.com/p/2235516502?see_lz=1&pn=%d' % i for i in range(1, 30)]
    keyword = "枯树"
    kw = urllib.quote(keyword)
    start_urls = [
        'http://image.baidu.com/search/avatarjson?tn=resultjsonavatarnew&word=%s&pn=%d&rn=60&itg=0&z=0&fr=&width=&height=&lm=-1&ic=0&s=0&st=-1&gsm=350700003c' % (kw, i) for i in range(1, 1801, 60)]
    image_names = {}

    def parse(self, response):

        item = BaiDuTieBaItem()
        # item['image_urls'] = response.xpath("//img[@class='BDE_Image']/@src").extract()
        # item['image_urls'] = response.xpath("//img[@class='main_img img-hover']/@src").extract()
        json_response = json.loads(response.body_as_unicode())
        item['image_urls'] = [img['objURL'] for img in json_response['imgs']]
        for index, value in enumerate(item['image_urls']):
            number = self.start_urls.index(response.url) * len(item['image_urls']) + index
            self.image_names[value] = 'full/%04d.jpg' % number
        yield item

    # def make_requests_from_url(self, url):
    #     yield Request(url, meta={'dont_redirect': True, 'handle_httpstatus_list': [301, 302]})

