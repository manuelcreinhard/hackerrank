my $cases = <>;
chomp $cases;
for(my $i = 0; $i < $cases;$i++){
	my $line = <>;
	chomp $line;
	if($line =~ /^hi\s[^dD]/i){
		print "$line\n";
	}
}
