'use strict';

var main = require('../lib/main');

describe('test', function() {
  it('returns hello world', function() {
    expect(main.test()).toBe('hello world');
  });
});

describe('TestObject', function() {
  it('returns hello world', function() {
    var obj = new main.TestObject();
    expect(obj.test()).toBe('hello world');
  });
});
