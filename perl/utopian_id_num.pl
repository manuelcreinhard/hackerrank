my $cases = <>;
chomp $cases;
for(my $i = 0; $i < $cases; $i++){
	my $line = <>;
	chomp $line;
	if($line =~ /^[a-z]{0,3}[0-9]{2,8}[A-Z]{3,}$/){
		print "VALID\n";
	} else {
		print "INVALID\n";
	}
}
