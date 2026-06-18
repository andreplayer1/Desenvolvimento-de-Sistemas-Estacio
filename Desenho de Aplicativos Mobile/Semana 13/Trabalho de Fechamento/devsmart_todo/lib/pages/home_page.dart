import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'add_task.dart';
import 'task_detail.dart';

// ---------------------- Tela Principal ----------------------
class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  List<String> tasks = []; // Lista de tarefas

  @override
  void initState() {
    super.initState();
    _loadTasks(); // Carrega tarefas salvas ao iniciar
  }

  // Função para carregar tarefas do armazenamento local
  Future<void> _loadTasks() async {
    final prefs = await SharedPreferences.getInstance();
    setState(() {
      tasks = prefs.getStringList('tasks') ?? [];
    });
  }

  // Função para salvar tarefas no armazenamento local
  Future<void> _saveTasks() async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setStringList('tasks', tasks);
  }

  // Adiciona nova tarefa
  void _addTask(String task) {
    setState(() {
      tasks.add(task);
    });
    _saveTasks();
  }

  // Remove tarefa pelo índice
  void _deleteTask(int index) {
    setState(() {
      tasks.removeAt(index);
    });
    _saveTasks();
  }

  // Edita tarefa pelo índice
  void _editTask(int index, String newTask) {
    setState(() {
      tasks[index] = newTask;
    });
    _saveTasks();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Easy List')), // Barra superior
      body: ListView.builder(
        itemCount: tasks.length, // Número de tarefas
        itemBuilder: (context, index) {
          return Semantics(
            label:
                'Missão: ${tasks[index]}. Toque duas vezes para ver os detalhes',
            child: Card(
              color: Theme.of(context).colorScheme.surface,
              margin: const EdgeInsets.only(bottom: 12),
              child: ListTile(
                title: Text(tasks[index]), // Exibe tarefa
                onTap: () {
                  // Abre tela de detalhes ao clicar
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (_) => TaskDetailPage(
                        task: tasks[index],
                        onDelete: () => _deleteTask(index),
                        onEdit: (newTask) => _editTask(index, newTask),
                      ),
                    ),
                  );
                },
              ),
            ),
          );
        },
      ),
      floatingActionButton: Semantics(
        label: 'Adicionar nova missão',
        child: FloatingActionButton(
          onPressed: () async {
            // Abre tela de adicionar tarefa
            final newTask = await Navigator.push(
              context,
              MaterialPageRoute(builder: (_) => const AddTaskPage()),
            );
            if (newTask != null) _addTask(newTask);
          },
          child: const Icon(Icons.add), // Ícone "+"
        ),
      ),
    );
  }
}
