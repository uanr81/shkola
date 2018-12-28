(defun меню_Звезда_Двоеточие ()
  "Из строк создать шаблон меню режима texi"
  (interactive)
  (setq nashalus (region-beginning))
  (setq konetus (region-end))
  (goto-char nashalus)  
  (while (re-search-forward "^.*" konetus t)
    (replace-match (concat "*" (match-string 0) "::") t)
    (setq konetus (+ 3 konetus)))
  )

(defun ноды_из_меню ()
  "Из меню пометить ноды"
  (interactive)
  (setq spis '())
  (setq respis '())
  (setq nashalus (region-beginning))
  (setq konetus (region-end))
  (goto-char nashalus)  
  (while (re-search-forward "^*[[:alpha:]]*::" konetus t)
    (setq respis (cons (substring (match-string 0) 1 -2) respis))
    )
  (set-match-data nil)
  (while respis
    (setq spis (cons (car respis) spis))
    (setq respis (cdr respis)))
  (goto-char konetus)
  (while spis
    (set-match-data nil)
    (setq isk "")
    (setq isk (concat "^" (car spis) "$"))
    (if (re-search-forward isk nil t 1)
	(let* ((str (match-string 0)) 
	       (strNoda (concat "@node " str))
	       (strIfInfo (concat "
@ifinfo
@heading " str "
@end ifinfo"))
	       (strZamen (concat strNoda strIfInfo)))
	  (replace-match strZamen t)
	  (setq spis (cdr spis))
	  )
      (message "Не найдено ноды из меню: %s" (car spis))
      )))

(defun КонецОпредФункции ()
  "Прилипить @end deffn в конце определения функции"
  (interactive)
  (setq str "@end deffn")
  (while (re-search-forward "^Доступность$" nil t)
    (dired-next-line 2) (insert str)(open-line 1)
    )
  )

(defun НачалоОпредФункции ()
  "Прилипить @deffn в начале определения функции"
  (interactive)
  (setq str "@deffn Функция")
  (while (re-search-forward "^ Функция" nil t)
    (replace-match str t)
    )
  )
(defun НачалоОпредПроцедуры ()
  "Прилипить @deffn в начале определения процедуры"
  (interactive)
  (setq str "@deffn Процедура")
  (while (re-search-forward "^ Процедура" nil t)
    (replace-match str t)
    )
  )

(defun ОбозначитьРаздел ()
  "Прилипить @section и название ноды"
  (interactive)
  (set-match-data nil)
  (setq isk (concat "^@node [[:alpha:]]+$"))
  (while (re-search-forward isk nil t)
    (progn (setq najStr (concat "@section " (substring (match-string 0) 5 )))
    (open-line 1) (next-line)(insert najStr)))
  )


(defun ОформлениеФункций ()
  "Выделить жирным в отдельной строке"
  (interactive)
  (setq endexmp "@end example")
  (setq exmp "@example")
  (setq nashPoz (point))
  (setq art '("Синтаксис" "Параметры" "Расположение" "Возвращаемое значение" "Пример вызова" "Пример реализации" "Доступность"))
  (while art
    (let* ((obj (concat (car art)))(newobj (concat "@*@b{" obj "}@*"))(str (concat "^" obj "$"))
	   (set-match-data nil))
      (while (re-search-forward str nil t 1)
	(progn
	  (replace-match newobj t) 
	  (cond 
	   ((string-equal "Параметры" obj)(progn (open-line 1)(next-line)(insert exmp)
						 (next-line)(beginning-of-line)
						 (while (string= (string (char-after)) " ")
						   (progn (move-end-of-line 1)(next-line)(beginning-of-line)))
						 (open-line 1)(insert endexmp)))
	   ((string-equal "Возвращаемое значение" obj)(progn (open-line 1)(next-line)(insert exmp)
							     (next-line)(beginning-of-line)
							     (while (string= (string (char-after)) " ")
							       (progn (move-end-of-line 1)(next-line)(beginning-of-line)))
							     (open-line 1)(insert endexmp)))
	   ((string-equal "Пример реализации" obj)(progn (open-line 1)(next-line)(insert exmp)
							     (next-line)(beginning-of-line)
							     (while (string= (string (char-after)) " ")
							       (progn (move-end-of-line 1)(next-line)(beginning-of-line)))
							     (open-line 1)(insert endexmp)))
	   )
	  )
	)
      )
    (goto-char nashPoz)(setq art (cdr art))
    )
  )

