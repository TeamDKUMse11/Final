var cheerio = require('cheerio');
var request = require('request');
var fs = require('fs');

var url = [ 'http://www.dankook.ac.kr/web/kor/d1_3_1_1', //교직원식당
            'http://www.dankook.ac.kr/web/kor/d1_3_1_2', //학생식당
            'http://www.dankook.ac.kr/web/kor/d1_3_1_3', //기숙사식당
            'http://www.dankook.ac.kr/web/kor/1196'];    //키친트리

request(url[0], function (drror, response, html) {
    if (error) { throw error };

    var $ = cheerio.load(html);

    $('#boardsec').each(function () {
        fs.writeFile("교직원식당 메뉴.txt", $(this).text());
    })
});