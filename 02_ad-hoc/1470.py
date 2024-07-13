import sys

'''
The problem is solved using brute force, but with some stopping conditions
to optimize time, and storage update to optimize in memory.

The folds were implemented by recursion, following the following logic: the input tape
is folded into all possible positions (a single fold) and the tapes obtained are stored.
And in the meantime, each tape resulting from the fold has already been compared to the
output tape, to check if they are equals. If none of them match, they are folded in the
same way (a single fold in each possible position), until you find one that is equivalent
to the output tape.

If after all possible folds have been made, none match the output tape, then there is no
solution, indicating a problem with the bending machine in question.
'''

def bending_machine(divisor, content_tape_1):
    
    content_tape_1_bend = content_tape_1[0:divisor]
    content_tape_2_bend = content_tape_1[divisor:len(content_tape_1)]
    len_content_tape_1_bend = len(content_tape_1_bend)
    len_content_tape_2_bend = len(content_tape_2_bend)
    
    bigger = 1
    if len(content_tape_1_bend) < len(content_tape_2_bend):
        bigger = 2
    
    # preenchendo a partição menor com zeros, para ambas terem o mesmo tamanho e facilitar a soma elemento à elemento    
    if bigger == 1:
        difference_len = len_content_tape_1_bend - len_content_tape_2_bend
        for _ in range(len_content_tape_2_bend, len_content_tape_2_bend + difference_len):
            content_tape_2_bend.append(0)
    else:
        difference_len = len_content_tape_2_bend - len_content_tape_1_bend
        for _ in range(len_content_tape_1_bend, len_content_tape_1_bend + difference_len):
            content_tape_1_bend.insert(0, 0)
    
    # IMPORTANTE! É a fita 2 que dobra (ou inverte para a soma)
    inverted_tape_2 = content_tape_2_bend[::-1]
    bended_tape = [content_tape_1_bend[i] + inverted_tape_2[i] for i in range(len(content_tape_1_bend))]      

    return bended_tape


def recursive_iterator(list_tapes, content_tape_2):
    
    len_tape_2 = len(content_tape_2)
    intern_list_tapes = []
    answer = 'N'
    
    for tape in list_tapes:
        for divisor in range(1, len(tape)):
            bended_tape = bending_machine(divisor, tape)
            intern_list_tapes.append(bended_tape)
            len_tape_1 = len(bended_tape)
            
            # Quando a fita 1 é reduzida ao tamanho da fita 2, pode-se compará-las (obs: está incluído o caso de dobra na posição zero, que só inverte a lista)

            if len_tape_1 == len_tape_2:
                if bended_tape == content_tape_2 or bended_tape[::-1] == content_tape_2:
                    answer = 'S'
                    return answer
            
            if len_tape_1 < len_tape_2 or len_tape_1 == 1:
                return answer

    return recursive_iterator(intern_list_tapes, content_tape_2)


if __name__ == "__main__":
    
    with open('3_maquina_dobradora.txt', 'r') as file:
        all_rows = file.readlines() 
        
    #all_rows = sys.stdin.readlines()

    n_instances = len(all_rows)

    count_instances = 0

    while count_instances < n_instances:
               
        content_tape_1 = all_rows[count_instances + 1].split()
        content_tape_1 = [int(i) for i in content_tape_1]
       
        content_tape_2 = all_rows[count_instances + 3].split()
        content_tape_2 = [int(i) for i in content_tape_2]

        if content_tape_1 == content_tape_2 or content_tape_1[::-1] == content_tape_2:
            output = 'S'
        else:
            list_tapes = [content_tape_1]
            output = recursive_iterator(list_tapes, content_tape_2)
        
        print(output)
        
        count_instances += 4