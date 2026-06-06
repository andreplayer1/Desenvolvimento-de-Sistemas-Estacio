<?php
header("Content-Type: application/json; charset=utf-8");// Avisamos que a resposta do servidor será no formato JSON

// Simulação de Banco de Dados
$estoque = [
    1 => ["nome" => "Gabinete Montech King 95", "categoria" => "componentes", "preço" => 700.00],
    2 => ["nome" => "Placa de Video RTX 5060", "categoria" => "componentes", "preço" => 2500.00],
    3 => ["nome" => "Memoria RAM Team Force Delta RGB 16GB", "categoria" => "componentes", "preço" => 450.00],
    4 => ["nome" => "Processador Ryzen 5 5700X", "categoria" => "componentes", "preço" => 1100.00],
    5 => ["nome" => "SSD Kingston NV3", "categoria" => "componentes", "preço" => 900.00],
    6 => ["nome" => "Placa Mãe MSI MPG B550", "categoria" => "componentes", "preço" => 999.00],
    7 => ["nome" => "Teclado Machenike K500W", "categoria" => "perifericos", "preço" => 643.00],
    8 => ["nome" => "Mouse Atack Shark X11", "categoria" => "perifericos", "preço" => 169.90],
    9 => ["nome" => "Controle Gamesir T4 Pro", "categoria" => "perfifericos", "preço" => 379.00],
    10 => ["nome" => "Monitor LG Ultrawide 29", "categoria" => "monitores", "preço" => 1100.]
];

$termoBuscado = $_GET["busca"] ?? ""; // Pega o que vier na URL se não vier nada guarda vazio ('')

$resultados = []; // Gaveta para guardar o que encontramos

// Se o usuário digitou alguma coisa...
if ($termoBuscado !== '') {
    foreach ($estoque as $id => $produto) { // Passamos por cada item do estoque

        // Transformamos o nome do produto e a busca em minúsculas
        $nomeProduto = mb_strtolower($produto["nome"], 'UTF-8');
        $busca = mb_strtolower($termoBuscado, 'UTF-8');

        // A função str_contains verifica se a palavra buscada existe DENTRO do nome
        if (str_contains($nomeProduto, $busca)) {
            $produto["id"] = $id; //Guarda o ID junto
            $resultados[] = $produto; // Coloca na gaveta resultados
        }
    }
}

echo json_encode($resultados);

?>