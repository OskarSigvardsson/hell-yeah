project('hell-yeah', 'c', default_options: ['buildtype=release'])

e1 = executable('hell-yeah-printf',     sources: [ 'src/printf.c' ],     install: true)
e2 = executable('hell-yeah-non-buffer', sources: [ 'src/non-buffer.c' ], install: true)
e3 = executable('hell-yeah-buffer',     sources: [ 'src/buffer.c' ],     install: true)
e4 = executable('hell-yeah-fwrite',     sources: [ 'src/fwrite.c' ],     install: true)
#e5 = executable('hell-yeah-splice',     sources: [ 'src/splice.c' ],     install: true)

p1 = e1.full_path()
p2 = e2.full_path()
p3 = e3.full_path()
p4 = e4.full_path()
#p5 = e5.full_path()

tester = find_program('./test.sh')

test('t1-1', tester, args: ['yes'])
test('t1-2', tester, args: [p1])
test('t1-3', tester, args: [p1, 'ye'])
test('t1-4', tester, args: [p1, 'y', '0'])
test('t1-5', tester, args: [p1, 'y', '4100'])

test('t2-1', tester, args: ['yes'])
test('t2-2', tester, args: [p2])
test('t2-3', tester, args: [p2, 'ye'])
test('t2-4', tester, args: [p2, 'y', '0'])
test('t2-5', tester, args: [p2, 'y', '4100'])

test('t3-1', tester, args: ['yes'])
test('t3-2', tester, args: [p3])
test('t3-3', tester, args: [p3, 'ye'])
test('t3-4', tester, args: [p3, 'y', '0'])
test('t3-5', tester, args: [p3, 'y', '4100'])

test('t4-1', tester, args: ['yes'])
test('t4-2', tester, args: [p4])
test('t4-3', tester, args: [p4, 'ye'])
test('t4-4', tester, args: [p4, 'y', '0'])
test('t4-5', tester, args: [p4, 'y', '4100'])
