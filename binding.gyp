{
  'targets': [
    {
      'target_name': '<(module_name)',
      'include_dirs': [ '<!(node -e "require(\'nan\')")' ],
      'cflags': [
        '-std=c++11',
        '-O3',
      ],
      'xcode_settings': {
        'OTHER_CPLUSPLUSFLAGS': [
          '-std=c++11',
          '-O3',
          '-stdlib=libc++',
        ],
        'MACOSX_DEPLOYMENT_TARGET': '10.7',
      },
      'sources': [
        'src/binding.cpp',
      ],
      'conditions': [
        ['OS == "win"', {
          'defines': ['_HAS_EXCEPTIONS'],
          'msvs_disabled_warnings': [
            4267,  # conversion from 'size_t' to 'int', possible loss of data
            4530,  # exception unwinding
          ],
        }],
      ],
    },
    {
      'target_name': 'action_after_build',
      'type': 'none',
      'dependencies': [ '<(module_name)' ],
      'copies': [
        {
          'files': [ '<(PRODUCT_DIR)/<(module_name).node' ],
          'destination': '<(module_path)'
        }
      ]
    }
  ]
}
