Lista bubbleSort(Lista L)
{
    int n, fim, j, k;
    int aux;

    n = L.tamanho; fim = n-1;

    for(j = 1; j <= n-1; j++)
    {
        for(k = 1; k <= fim - 1; k++)
        {
            if(L.vetor[k] > L.vetor[k+1])
            {
                aux = L.vetor[k];
                L.vetor = L.vetor[k+1];
                L.vetor[k+1] = aux;

            }

        }

    fim--

    }

}