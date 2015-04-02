my $a = 'abc';
my $b = 'abd';
my $c = $b - $a;
print "diff: $c\n";

my $str = "hello youthere";
my $index = index $str, "you";
$index += 3;
my $sub = substr $str,$index,1;
print "index: $index\n";
print "sub: $sub\n";
