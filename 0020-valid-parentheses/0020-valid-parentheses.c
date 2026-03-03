bool isValid(char* s) {
    int len = 0;
    
    // Find length manually (since strlen costs extra pass)
    while (s[len] != '\0') {
        len++;
    }
    
    char* stack = (char*)malloc(len);
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        
        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else {
            // If stack empty → invalid
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char topChar = stack[top--];
            
            // Check matching
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }
    
    bool valid = (top == -1);
    free(stack);
    return valid;
}