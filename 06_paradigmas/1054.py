import sys

'''
The algorithm consists of checking the frog's route in both directions, that is, going towards the
opposite bank and returning. On the way, the frog jumps over the odd small and large stones.
On the way back, he jumps over the small pairs (that is, those that were not used on the way there)
and the large ones. This way, the biggest jump on the way out and the biggest on the way back are
calculated, where the biggest one represents the maximum jump on the optimized path.
'''

def map_path(D, info_rocks):
    
    # Importante! Definindo as próprias margens como sendo uma pedra grande (adicionando-as no inicio e no fim da lista)
    # Esse passo serve para demarcar o primeiro e o último caminhos intermediários
    info_rocks.insert(0, 'B-0')
    info_rocks.append('B-{}'.format(D))
    
    # identificando o indice da primeira pedra pequena para iniciar a marcação das pares e ímpares
    first_odd = 0
    for i in range(1, len(info_rocks)):
        if info_rocks[i][0] == 'S':
            first_odd = i
            break
    
    # adicionando todas as pedras anteriores à primeira pequena como sendo big, caso haja
    even_odd_rocks = []
    for i in range(first_odd):
        even_odd_rocks.append('big')
    
    if first_odd != 0:
        even_odd_rocks.append('odd') # inserindo a primeira impar exatamente na sua posição

        marker = 0
        for i in range(first_odd + 1, len(info_rocks)):        
            if info_rocks[i][0] == 'S':
                marker += 1
            if marker % 2 != 0 and info_rocks[i][0] != 'B':
                even_odd_rocks.append('even')
            if marker % 2 == 0 and info_rocks[i][0] != 'B':
                even_odd_rocks.append('odd')
            if info_rocks[i][0] == 'B':
                even_odd_rocks.append('big')
                
    else:
        even_odd_rocks = ['big' for _ in info_rocks]
    
    # armazenando somente as distâncias já que a lista even_odd_rocks armazena as outras informações
    info_rocks = [int(i[2:]) for i in info_rocks]    

    return info_rocks, even_odd_rocks


def min_major_jump(info_rocks, even_odd_rocks):

    min_major = 0
    
    #### ida 
    j = 0 # ponteiro que marca a ultima pedra que o sapo esteve (exluindo as que são saltadas para a volta) antes da atual 
    for i in range(1, len(info_rocks)):
        if even_odd_rocks[i] == 'odd' or even_odd_rocks[i] == 'big':
            jump_distance = info_rocks[i] - info_rocks[j]
            j = i
            min_major = max(min_major, jump_distance)

    #### volta
    j = len(info_rocks) - 1
    for i in range(len(info_rocks) - 1, -1, -1):
        if even_odd_rocks[i] == 'even' or even_odd_rocks[i] == 'big':
            jump_distance = info_rocks[j] - info_rocks[i]
            j = i
            min_major = max(min_major, jump_distance)
            
    return min_major


if __name__ == "__main__":
    
    all_rows = sys.stdin.readlines()

    T = int(all_rows[0])

    count_instances = 1

    answers = []
    
    while count_instances < len(all_rows):
        info_input = all_rows[count_instances].split()
        N, D = int(info_input[0]), int(info_input[1])
        
        # caso de não haver pedras, ele só pula de uma margem à outra
        if N == 0:
            answers.append(D)
            count_instances += 1
        
        else:
            info_rocks = all_rows[count_instances + 1].split()
            
            info_rocks, even_odd_rocks = map_path(D, info_rocks)
            
            solution = min_major_jump(info_rocks, even_odd_rocks)
            
            answers.append(solution)
            count_instances += 2
        
    for i, answer in enumerate(answers):
        print('Case {}: {}'.format(i + 1, answer))