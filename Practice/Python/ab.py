# from tkinter import N


# T(n) = n*T(n-1) + n, T(1) = 1

# find time complexity of above function in big O notation

# solution: T(n) = n*T(n-1) + n
#           T(n) = (n*(n-1)*T(n-2) + n*(n-1)) + n
#           T(n) = (n*(n-1)*(n-2)*T(n-3) + n*(n-1)*(n-2)) + n*(n-1) + n
#           T(n) = (n*(n-1)*(n-2)*(n-3)*T(n-4) + n*(n-1)*(n-2)*(n-3)) + n*(n-1)*(n-2) + n*(n-1) + n
#           T(n) = (n*(n-1)*(n-2)*(n-3)*(n-4)*T(n-5) + n*(n-1)*(n-2)*(n-3)*(n-4)) + n*(n-1)*(n-2)*(n-3) + n*(n-1)*(n-2) + n*(n-1) + n
# and so on...
#           T(n) = n! * T(1) + n! * (n-1) + n! * (n-1) * (n-2) + n! * (n-1) * (n-2) * (n-3) + ... + n! * (n-1) * (n-2) * (n-3) * ... * 1

