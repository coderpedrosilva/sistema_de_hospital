# SISTEMA DE HOSPITAL

Esse é um sistema em linguagem C para cadastro de pacientes diagnosticados com Covid-19. Foi desenvolvido como atividade do primeiro semestre do curso superior de tecnologia de análise e desenvolvimento de sistemas da Universidade Paulista. Para sua execução plena é recomendado o uso da IDE CodeBlocks.

![](img-readme/foto_1.jpg)
 
Inicialmente o profissional de saúde que utilizar o sistema verifica se o paciente tem Covid-19:

![](img-readme/foto_2.jpg)
 
Caso o paciente receba o diagnóstico positivo o profissional é levado a tela de login, o usuário é “enfermeira” e a senha ”123456”:

![](img-readme/foto_3.jpg)
 
Na tela de cadastro são captados os dados pessoais e endereço do paciente. Nessa parte do código há uma função que filtra somente CPF válidos e outra função para validar datas de nascimento válidas:

![](img-readme/foto_4.jpg)
 
Ao confirmar e digitar se o paciente tem comorbidade a informação é armazenada:

![](img-readme/foto_5.jpg)
 
O sistema calcula a idade do paciente, verificar se ele tem alguma comorbidade e dessa forma confirma se o mesmo pertence ao grupo de risco (acima de 65 anos ou com comorbidade).
Os dados são salvos em um arquivo .txt gerado dentro da pasta do sistema, para consulta a qualquer momento:

![](img-readme/foto_6.jpg)
 
Caso faça parte do grupo de risco, são salvas em outro arquivo .txt as informações de CEP e idade do paciente para serem enviadas para a central da Secretaria de Saúde da cidade.
Após a realização do cadastro há a opção de prosseguir com um novo cadastro:

![](img-readme/foto_7.jpg)
 
Caso a escolha seja não, o sistema é encerrado:

![](img-readme/foto_8.jpg)
