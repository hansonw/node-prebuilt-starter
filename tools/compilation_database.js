#!/usr/bin/env node
'use strict';

var fs = require('fs');
var path = require('path');

var db = [];
var sources = fs.readdirSync('src');
for (var i = 0; i < sources.length; i++) {
  var source = sources[i];
  db.push({
    directory: path.resolve('src'),
    file: source,
    command: (
      'clang -x c++ -std=c++14 -I ../node_modules/nan ' +
      '-I %s/.node-gyp/0.12.2/deps/v8/include ' +
      '-I %s/.node-gyp/0.12.2/src ' +
      '-I %s/.node-gyp/0.12.2/deps/uv/include'
    ).replace(/%s/g, process.env.HOME),
  });
}

fs.writeFileSync('compile_commands.json', JSON.stringify(db));
