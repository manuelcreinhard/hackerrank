my $cases = <>;
chomp $cases;
for(my $i = 0; $i < $cases;$i++){
	my $line = <>;
	chomp $line;
	if($line =~ /([0-9]{1,3})[- ]([0-9]{1,3})[- ]([0-9]{4,10})/i){
		print "CountryCode=$1,LocalAreaCode=$2,Number=$3\n"
	}
}
