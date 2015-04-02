# Enter your code here. Read input from STDIN. Print output to STDOUT
use strict;
use warnings;
my $lines = <>;
my $line;
my @list = ();
my @seq = ();
for(my $i = 0; $i < $lines;$i++){
	$line = <>;
	#chomp $line;
	$line = int($line);
	push @list, $line;
	print "$i\n" if $i%100000 == 0;
}
my $len = scalar(@list);
print "length: $len\n";

for(my $i = 0; $i < scalar(@list) - 1 ;$i++){
	longestSub($i) if !defined($seq[$i]);
}
$len = scalar(@seq);
print "length seq: $len\n";
@seq = sort { $a <=> $b } @seq;
my $longest = $seq[$len- 1];
print "$longest\n";

sub longestSub{
	my $pos = shift;
	print "$pos: $list[$pos]\n" if $pos > 999980;
	if($pos == scalar(@list) - 1){
		$seq[$pos] = 1;
		return 1;
	}
	my $j;
	for($j = $pos + 1; $j < scalar(@list) - 1; $j++){
		#print "pos $pos  --- j $j\n" if $pos > 999980;
		if($list[$pos] < $list[$j]){
			#print "$pos: $list[$pos] < $j: $list[$j]\n" if $pos > 999980;
			last;
		}
	}
	if($seq[$j]){
		print "seq of $j existed\n" if $pos > 999980;
		$seq[$pos] = $seq[$j] + 1;
	} else { 
		print "seq of $j did not exist\n" if $pos > 999980;
		$seq[$pos] = longestSub($j) + 1;
	}
	print "longest for $pos: $list[$pos]\n" if $pos > 999980;
	return $seq[$pos];
}
