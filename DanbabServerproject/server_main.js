var http = require('http');
var fs = require("fs");
var url = require("url");
var querystr = require("querystring");
var port = process.env.port || 8998;

var date = new Date();


http.createServer(function (req, res) {
    var query = url.parse(req.url).query;
    var filename = querystr.parse(query).file + ".json";

    res.writeHead(200, { 'Content-Type': 'text/plain; charset = utf-8' });

    setTimeout(function() {
        fs.readFile("Data/"+ filename,'utf8',function(err,data) {
            if(err) {
                switch(date.getDay()){
                    case 1:
                        filename="Mon.json";
                        break;
                    case 2:
                        filename="Tue.json";
                        break;
                    case 3:
                        filename="Wed.json";
                        break;
                    case 4:
                        filename="Thu.json";
                        break;
                    case 5:
                        filename="Fri.json";
                        break;
                    case 6:
                        filename="Sat.json";
                        break;
                }
                data = fs.readFileSync('Data/'+filename,'utf8');
                res.write(data);
                res.end();
            }
            else {
                res.write(data);
                res.end();
            }
        });
     },2000)
}).listen(port);

