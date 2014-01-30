//Given a string, write a routine that converts the string to a long, without using the built in functions that would do this.

//Parses the string interpreting its content as an integral number, which is returned as a value of type long int.The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many base-10 digits as possible, and interprets them as a numerical value.The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function. If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed and zero is returned.

//Concerns: if string is a string then return is 0, the LongLong value returns 0

-(long)getLongValue:(NSString *)stringVal
{
    //get rid of whitespace
    stringVal = [stringVal stringByReplacingOccurrencesOfString:@" " withString:@""];
    
    //check length of string shgould be not be greater than 10
    if(stringVal.length > 10)
        NSLog(@"Lenght of string greater than 10");
   
    //check for negative
    BOOL minusSign ;
    if([[stringVal substringToIndex:1]  isEqual:@"-"])
        minusSign = true;
    
    //check if minus sign is anywhere in the string
    stringVal =[stringVal stringByReplacingOccurrencesOfString:@"-" withString:@""];
    
    long result =0;
    int factor =1;
    for (int i = [stringVal length]; i > 0 ; i--) {
        NSString *ch = [stringVal substringWithRange:NSMakeRange(i-1, 1)];
        int convertString =[ch intValue];
        NSLog(@"Long Value is %d",convertString);
        result = result+convertString*factor;
        factor =factor*10;
    }
    if(minusSign)
        result =result*-1;
    
    NSLog(@"Result is %ld",result);
    
    //to test if the long worked
    long val = [stringVal longLongValue];
    NSLog(@"LongVAl is %ld",val);
    return result;
}