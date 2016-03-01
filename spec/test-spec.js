'use strict';

var main = require('../lib/main');

describe('test', function() {
  it('returns hello world', function() {
    expect(main.test()).toBe('hello world');
  });
});
