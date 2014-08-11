var cheerio = require('cheerio');
var request = require('request');
var fs = require('fs');

var url  = 'http://www.dankook.ac.kr/web/kor/d1_3_1_1';
var path = 'Data/Professor.txt';
var manuStr;

setInterval(function () {
    request(url,function(error,reponse,html){
        if(error){
            console.log('Menu Update Error (Professor)');
            throw error;
        }

        var $ = cheerio.load(html);

        $('#boardsec').each(function() {
            menuStr = $(this).text();
            fs.writeFileSync(path,menuStr);
        });
    }
    });
