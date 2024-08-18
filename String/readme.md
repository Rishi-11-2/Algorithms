## Optimized  String hashing

> pref[r+1]=( p^(r+1) + a[0] * p^(r) + a[1] * p^(r-1) + a[2] * p^(r-2) + ..+ a[l-1] > * p^((r+1)-(l-1+1))+a[l] * p^((r+1)-(l+1))  .. a[r-1] * p + a[r] )
>         pref[l]=( p^l + a[0] * p^(l-1) + a[1] * p^(l-2) + a[2] * p^(l-3) + ...a[l-2] * p +  a[l-1])
>        p^(r-l+1) * pref[l] = ( p^(r+1) + a[0] * p^(r) + a[1] * p^(r-1) +.... + a[l-1] * p^(r-l+1) )
>        pref[r+1]-( pref[l]*p^(r-l+1) ) = a[l] * p^(r-l) + a[l+1] * p^(r-l-1) +.... + a[r-1] * p + a[r]
