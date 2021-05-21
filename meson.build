# SPDX-License-Identifier: GPL-2.0-only

project	('termtris', 'cpp',
	version : '0.1.0',
	default_options : ['cpp_std=c++2a',
			   'warning_level=1',
			   'werror=true',
			  ]
	)

C = 'clang'
cpp = meson.get_compiler('cpp')

add_global_arguments('-Wno-pedantic',
		     language : 'cpp')

src = ['src/main.cpp',
       'src/tetris.cpp',
       'src/playfield.cpp',
       'src/score.cpp',
      ]

incdir = include_directories('include')

message('Fetching finalcut dependency...')
fc = run_command('git', 'submodule', 'update', '--init', '.third-party/finalcut')
if fc.returncode() != 0
  error('Fetching finalcut failed!')
endif

message('Compiling finalcut dependency...')
fc = run_command('./.install-deps')
if fc.returncode() != 0
  error('Compiling finalcut dependency failed!')
endif

fc_libdir = meson.current_source_dir() + '/.third-party/finalcut/src/.libs/'
message(fc_libdir)
fc_dep = cpp.find_library('final', dirs : fc_libdir)
fc_incdir = include_directories('.third-party/finalcut/src/include')

executable('termtris',
	   sources: src,
	   include_directories : [ incdir, fc_incdir ],
       dependencies: fc_dep
	   )
