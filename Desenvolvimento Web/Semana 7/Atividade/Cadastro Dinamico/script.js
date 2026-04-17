let form = document.getElementById('form');

form.addEventListener("submit", function(e) {
    e.preventDefault();

    //Capturando os elementos do HTML
    let nome = document.getElementById('nome');
    let email = document.getElementById('email');
    let senha = document.getElementById('senha');

    let erroNome = document.getElementById('erroNome');
    let erroEmail = document.getElementById('erroEmail');
    let erroSenha = document.getElementById('erroSenha');

    //Essa parte apaga a mensagem de erro depois que o usuario corrige o campo de input
    erroNome.innerText = '';
    erroEmail.innerText = '';
    erroSenha.innerText = '';

    let temErro = false;

    // Validação do nome
    if(nome.value.trim().length === 0){
        erroNome.innerText = 'Digite o seu nome';
        nome.style.borderColor = 'red';
        temErro = true;
    }else{
        nome.style.borderColor = 'green';
    }

    // Validação do email
    if(email.value.trim().length === 0){
        erroEmail.innerText = 'Digite o seu email';
        email.style.borderColor = 'red';
        temErro = true;
    }else{
        email.style.borderColor = 'green';
    }

    // Validação da senha
    if(senha.value.trim().length < 6){
        erroSenha.innerText = 'Crie uma senha com pelo menos 6 digitos';
        senha.style.borderColor = 'red';
        temErro = true;
    }else{
        senha.style.borderColor = 'green';
    }

    //Conclusão
    if(temErro === false){
        document.getElementById('confirmacao').innerText = 'Cadastro concluído!';
    }
})