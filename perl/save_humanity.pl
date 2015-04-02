my $cases = <>;
my $dna;
my $human;
my $len;
while($cases--){
	$human = <>;
	chomp $human;
	$dna = <>;
	chomp $dna;
	$len = length($dna);
	for my $i (0..length($human)-$len) {
		my $s = substr $human, $i, $len;
		my $x = $s ^ $dna;
		$x =~ tr/\0//d;  # equal characters xor to \0
		print "$i " unless length($x) > 1;
	}
	print "\n";
	<> if $cases > 0;
}
