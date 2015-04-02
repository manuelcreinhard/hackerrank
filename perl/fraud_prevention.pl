use Data::Dumper;
use strict;
my $addresses = {
	'street'     => "st.",
	'road'       => "rd."
};
my $cities = {
	"illinois"   => "il",
	"california" => "ca",
	"new york"   => "ny"
};

my $data = {};
run();
my $frauds = {};
foreach my $key (keys %{$data}){
	print Dumper $key;
	print Dumper $data->{$key};
	if(scalar @{$data->{$key}} > 1){
		for(my $i = 0; $i < scalar @{$data->{$key}}; $i++){
			for(my $j = $i+1; $j < scalar @{$data->{$key}}; $j++){
				my $data1 = ${$data->{$key}}[$i];
				my $data2 = ${$data->{$key}}[$j];
				if($data1->{"card"} != $data2->{"card"}){
					$frauds->{$data1->{"order"}} = 1;
					$frauds->{$data2->{"order"}} = 1;
				}
			}
		}
	}
}
my @orders = keys %{$frauds};
#forgot to sort by number... cost me doing this on the first attempt...
@orders = sort { $a <=> $b } @orders;
print join(",",@orders) . "\n";


sub stripEmail {
	my $email = shift;
	$email = lc($email);
	(my $name, my $domain) = split('@', $email);
	my @chars = split("",$name);
	$email = "";
	foreach (@chars) {
		next if $_ eq ".";
		last if $_ eq "+";
		$email .= $_;
	}
	$email .= '@' . $domain;
	return $email;
}


sub normalizeAddress {
	my $str = shift;
	print "Normalize address\n$str\n";
	$str = lc($str);
	print "$str\n";
	foreach my $key (keys %{$addresses}) {
            $str =~ s/$key/$addresses->{$key}/g;
    }
    print "$str\n";
    return $str;
}

sub normalizeCityState {
	my $str = shift;
	print "Normalize citystate\n$str\n";
	$str = lc($str);
	foreach my $key (keys %{$cities}) {
            $str =~ s/$key/$cities->{$key}/g;
    }
    print "$str\n";
    return $str;
}

sub run {
	my $line;
	my $cases = <>;
	while($cases--){
		$line = <>;
		chomp $line;
		(my $order, my $deal, my $email, my $address, my $city, my $state, my $zip, my $card) = split(",",$line);
		#Would be better to pass references, but I'm a bit lazy right now...
		print "email: $email\naddress: $address\ncity: $city\nstate: $state\n";
		$email = stripEmail($email);
		$address = normalizeAddress($address);
		$city = normalizeCityState($city);
		$state = normalizeCityState($state);
		my $data1 = {
			"order" => $order,
			"card" => $card
		};
=pod		
		if(!($data->{"$deal-$email"})){
			$data->{"$deal-$email"} = [];
		}
=cut
		push@{$data->{"$deal-$email"}}, $data1;
=pod		
		if(!($data->{"$deal-$address-$state-$city-$zip"})){
			$data->{"$deal-$email"} = [];
		}
=cut
		push@{$data->{"$deal-$address-$state-$city-$zip"}}, $data1;
		
		
		
	}	
}



