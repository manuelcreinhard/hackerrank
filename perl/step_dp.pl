use List::Util;
my @steps = ();
my $steps = 50;
my $ways = staircase($steps);
print "ways: $ways\n";

sub staircase{
	my $pos = shift;
	return 0 if($pos < 0);
	if($pos == 0){
		$steps[0] = 1;
		return 1;
	}
	return $steps[$pos] if($steps[$pos]);
	$steps[$pos] = staircase($pos-1) + staircase($pos-2) + staircase($pos-3);
	return $steps[$pos];
}
