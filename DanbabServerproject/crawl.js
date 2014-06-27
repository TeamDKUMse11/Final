var cheerio = require('cheerio');
var request = require('request');
var fs = require('fs');

var url = [ 'http://www.dankook.ac.kr/web/kor/d1_3_1_1', //교직원식당
            'http://www.dankook.ac.kr/web/kor/d1_3_1_2', //학생식당
            'http://www.dankook.ac.kr/web/kor/d1_3_1_3', //기숙사식당
            'http://www.dankook.ac.kr/web/kor/1196'];    //키친트리

var str = ['교직원 식당.txt',
              '학생 식당.txt',
              '기숙사 식당.txt',
              '키친트리.txt'];

function updateMenu() {
    for (var i = 0; i < 4; i++) {
        request(url[i], function (drror, response, html) {
            if (error) { throw error };

            var $ = cheerio.load(html);

            $('#boardsec').each(function () {
                fs.writeFile('Data/' + str[i], $(this).text());
            })
        });
    }
    console.log("Menu update");
};

setInterval("updateMenu()", 1000 * 3600);