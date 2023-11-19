void Black_Rose(char* input){
    int i = 1;
    int num_arr[6];
    
    read_six_numbers(input, &num_arr);

    if(num_arr[0] != 1){
        illegal_move();
    }
    while(i != 6){
        if(i % 2 == 0){
            if(num_arr[i] != num_arr[i-1] * i){
                illegal_move();
            }
            else{
                i++;
            }
        }
        else{
            if(num_arr[i] != num_arr[i-1] + i){
                illegal_move();
            }
            else{
                i++;
            }
        }
        if(i == 6){
            return;
        }
    }
}

/* 1 2 4 7 28 33 */