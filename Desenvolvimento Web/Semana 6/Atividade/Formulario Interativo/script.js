addEventListener("submit", resumir);

function resumir(event){
    event.preventDefault();

    let resumo = document.getElementById("resumo");
    let nome = document.getElementById("nome").value;
    let email = document.getElementById("email").value;
    let mensagem = document.getElementById("mensagem").value;

    //Validação de Campos
    if(nome.trim().length === 0){
        let erroNome = document.getElementById("erroNome");
        erroNome.innerText = 'Digite o seu nome.'
    }

    if(email.trim().length === 0){
        let erroEmail = document.getElementById("erroEmail");
        erroEmail.innerText = 'Digite o seu email.';
    }

    if(mensagem.trim().length === 0){
        let erroMensagem = document.getElementById("erroMensagem");
        erroMensagem.innerText = 'Digite algo no campo de texto.';
    }

    //Geração do card de resumo.
    if(nome.trim().length !== 0 && email.trim().length !== 0 && mensagem.trim().length !== 0){
        document.getElementById("titulo").innerHTML = "<h3>Resumo</h3>"
        resumo.innerText = `Nome: ${nome}\n Email: ${email}\n Mensagem: ${mensagem}`
        document.getElementById("botao2").innerHTML = "<button>Enviar</button>"
    }
}